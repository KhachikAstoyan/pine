#ifndef PINE_CORE_H 
#define PINE_CORE_H 

#include "pine.h"

Pine pineInit();
void pineProcessKeypress(Pine *p);
void pineRefreshScreen(Pine *p);

#endif // !PINE_CORE_H
