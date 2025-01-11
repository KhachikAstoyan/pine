#include "utils/term.h"
#include "pine/editor.h"
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>

int main(void) {
  termEnableRaw();
  atexit(termDisableRaw);

  while (1) {
    pineProcessKeypress(); 
    pineRefreshScreen();
  }

  return 0;
}
