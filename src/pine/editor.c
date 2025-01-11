#include "../utils/keyboard.h"
#include "../utils/term.h"
#include "editor.h"
#include <stdlib.h>
#include <unistd.h>

void pineProcessKeypress() {
  char c = kbReadKey();

  switch (c) {
    case CTRL_KEY('q'):
      exit(0);
      break;
  }
}

void pineRefreshScreen() {
  // clear the screen
  termClearScreen();
  termCrsrTopLeft();
}
