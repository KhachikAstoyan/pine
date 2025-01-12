#ifndef KEYBOARD_H
#define KEYBOARD_H

// bitwise and with 00011111
#define CTRL_KEY(k) ((k) & 0x1f)
#define ESCAPE '\x1b'

enum Key {
  ARROW_LEFT = 1000,
  ARROW_RIGHT,
  ARROW_UP,
  ARROW_DOWN,
  PAGE_UP,
  PAGE_DOWN
};

int kbReadKey();

#endif // !KEYBOARD_H
