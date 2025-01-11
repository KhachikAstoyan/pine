#ifndef TERM_H
#define TERM_H

#include <unistd.h>

void termEnableRaw();
void termDisableRaw();
static inline void termClearScreen() { write(STDOUT_FILENO, "\x1b[2J", 4); }
static inline void termCrsrTopLeft() { write(STDOUT_FILENO, "\x1b[H", 3); }

#endif
