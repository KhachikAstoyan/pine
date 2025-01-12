#ifndef PINE_RENDER_H
#define PINE_RENDER_H

#include "pine.h"
void pineRenderFrame(Pine *p);
void pineHideCrsr(abuf *ab);
void pineShowCrsr(abuf *ab);
void pineClrLineR(abuf *ab);
void pineRenderCrsr(Pine *p);
void pineWelcome(Pine *p);

#endif // !PINE_RENDER_H
