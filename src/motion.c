#include "motion.h"
#include "utils/keyboard.h"

void pineMoveCrsr(Pine *p, int key) {
  switch (key) {
    case ARROW_LEFT:
      if (p->cx != 0)
        p->cx--;
      break;
    case ARROW_RIGHT:
      if (p->cx != p->wincols - 1)
        p->cx++;
      break;
    case ARROW_UP:
      if (p->cy != 0)
        p->cy--;
      break;
    case ARROW_DOWN:
      if (p->cy != p->winrows - 1)
        p->cy++;
    break;
  }
}