#include "utils.h"
#include "term.h"
#include <errno.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  termEnableRaw();
  atexit(termDisableRaw);

  while (1) {
    char c = '\0';
    if(read(STDIN_FILENO, &c, 1) == -1 && errno != EAGAIN)
      die("main -> read");

    if (iscntrl(c)) {
      printf("%d\r\n", c);
    } else {
      printf("%d (%c)\r\n", c, c);
    }

    if(c == CTRL_KEY('q')) break;
  }

  return 0;
}
