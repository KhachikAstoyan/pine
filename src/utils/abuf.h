#ifndef ABUF_H
#define ABUF_H

#define ABUF_INIT {NULL, 0}

typedef struct {
  char *b;
  int len;
} abuf;

void abAppend(abuf *b, const char *s, int len);
void abFree(abuf *b, const char *s, int len);

#endif // !ABUF_H
#define ABUF_H
