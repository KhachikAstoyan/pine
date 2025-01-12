#include "core.h"
#include "utils/term.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

void cleanup() {
  termDisableRaw();
  termClearScreen();
  termCrsrTopLeft();
}

int main(void) {
  termEnableRaw();
  atexit(cleanup);

  Pine pine = pineInit();

  while (1) {
    pineRefreshScreen(&pine);
    pineProcessKeypress(&pine);
  }

  return 0;
}
