#include "render.h"
#include "pine.h"
#include <unistd.h>

void pineRenderFrame(Pine *p) {
  int y;
  for (y = 0; y < p->winrows; y++) {
    write(STDOUT_FILENO, "\x1B[35m~", 6);

    if(y < p->winrows - 1) {
      write(STDOUT_FILENO, "\r\n", 2);
    }
  }
}
