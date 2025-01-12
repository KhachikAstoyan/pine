#include "abuf.h"
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

bool abAppend(abuf *b, const char *s, size_t len) {
  size_t newLen = b->len + len;
  size_t newCap = b->cap;
  char *new = b->b;

  if(newLen >= b->cap) {
    newCap =  b->cap == 0 ? 16 : b->cap * 2; 

    while(newCap < newLen) {
      newCap *= 2;
    }

    new = realloc(b->b, newCap);
    if(new == NULL) return false;
  }  
  
  memcpy(&new[b->len], s, len);
  b->b = new;
  b->len = newLen;
  b->cap = newCap;

  return true;
}

void abClear(abuf *b) {
  b->len = 0;
  if(b->b != NULL) {
    b->b[0] = '\0';
  }
}

void abFree(abuf *b) {
  free(b->b);
}
