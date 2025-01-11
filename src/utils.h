#ifndef UTILS_H
#define UTILS_H

// bitwise and with 00011111
#define CTRL_KEY(k) ((k) & 0x1f)

// prints the error in errno and exits with
// status 1
void die(const char *s);

#endif
