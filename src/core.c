#include "core.h"
#include "motion.h"
#include "pine.h"
#include "render.h"
#include "utils/err.h"
#include "utils/keyboard.h"
#include "utils/term.h"
#include <stdlib.h>
#include <unistd.h>

Pine pineInit() {
  Pine pine;
  abuf ab = ABUF_INIT;
  pine.ab = ab;
  pine.cx = 0;
  pine.cy = 0;

  if (termGetWinSize(&pine.winrows, &pine.wincols) == -1)
    die("init > termGetWinSize");

  return pine;
}

void pineProcessKeypress(Pine *p) {
  int c = kbReadKey();

  switch (c) {
  case CTRL_KEY('q'):
    exit(0);
    break;
  case PAGE_UP:
  case PAGE_DOWN:
    {
      int times = p->winrows;
      while(times--)
        pineMoveCrsr(p, c == PAGE_UP ? ARROW_UP : ARROW_DOWN);
    }
    break;
  case ARROW_UP:
  case ARROW_DOWN:
  case ARROW_LEFT:
  case ARROW_RIGHT:
    pineMoveCrsr(p, c);
    break;
  }
}

void pineRefreshScreen(Pine *p) {
  // clear the screen
  termCrsrTopLeft();

  pineHideCrsr(&p->ab);
  pineRenderFrame(p);
  pineRenderCrsr(p);

  pineShowCrsr(&p->ab);
  write(STDOUT_FILENO, p->ab.b, p->ab.len);

  abClear(&p->ab);
}
