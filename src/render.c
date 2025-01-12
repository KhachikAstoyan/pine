#include "render.h"
#include "pine.h"
#include "utils/abuf.h"
#include "config.h"
#include <stdio.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>

void pineRenderFrame(Pine *p) {
  int y;
  for (y = 0; y < p->winrows; y++) {
    abAppend(&p->ab, "\x1B[34m~", 6);
    pineClrLineR(&p->ab);

    if(y == p->winrows / 3) {
      pineWelcome(p);
    } 

    if (y < p->winrows - 1) {
      abAppend(&p->ab, "\r\n", 2);
    }
  }
}

void pineWelcome(Pine *p) {
  char welcome[80];
  int len = snprintf(welcome, sizeof(welcome),
        "Pine editor -- version %s", VERSION);
  if(len > p->wincols) len = p->wincols;

  int padding = (p->wincols - len) / 2 - 1;

  while(padding--) abAppend(&p->ab, " ", 1);
  abAppend(&p->ab, welcome, len);
}

void pineRenderCrsr(Pine *p) {
  char buf[32];
  snprintf(buf, sizeof(buf), "\x1b[%d;%dH", p->cy + 1, p->cx + 1);
  abAppend(&p->ab, buf, strlen(buf));
}

void pineHideCrsr(abuf *ab) { abAppend(ab, "\x1b[?25l", 6); }

void pineShowCrsr(abuf *ab) { abAppend(ab, "\x1b[?25h", 6); }

void pineClrLineR(abuf *ab) { abAppend(ab, "\x1b[K", 3); }
