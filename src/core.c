#include "utils/keyboard.h"
#include "utils/term.h"
#include "utils/err.h"
#include "pine.h"
#include "render.h"
#include "core.h"
#include <stdlib.h>
#include <unistd.h>

Pine pineInit() {
  Pine pine;

  if(termGetWinSize(&pine.winrows, &pine.wincols) == -1)
    die("init > termGetWinSize");
  
  return pine;
}

void pineProcessKeypress(Pine *p) {
  char c = kbReadKey();

  switch (c) {
    case CTRL_KEY('q'):
      exit(0);
      break;
  }
}

void pineRefreshScreen(Pine *p) {
  // clear the screen
  termClearScreen();
  termCrsrTopLeft();

  pineRenderFrame(p);

  termCrsrTopLeft();
}
