#ifndef KEYBOARD_H
#define KEYBOARD_H

// bitwise and with 00011111
#define CTRL_KEY(k) ((k) & 0x1f)

char kbReadKey();

#endif // !KEYBOARD_H
