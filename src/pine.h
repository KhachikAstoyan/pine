#ifndef PINE_H
#define PINE_H

#include "utils/abuf.h"

typedef struct {
  int cx, cy;
  int winrows, wincols;
  abuf ab;
} Pine;

#endif // PINE_H
