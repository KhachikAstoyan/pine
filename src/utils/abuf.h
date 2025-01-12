#ifndef ABUF_H
#define ABUF_H

#include "stddef.h" 
#include "stdbool.h"
#define ABUF_INIT {NULL, 0, 0}

typedef struct {
  char *b;
  size_t len;
  size_t cap;
} abuf;

bool abAppend(abuf *b, const char *s, size_t len);
void abClear(abuf *b);
void abFree(abuf *b);

#endif // !ABUF_H
#define ABUF_H
