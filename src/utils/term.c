#include "term.h"
#include "err.h"
#include "keyboard.h"
#include <stdatomic.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include <sys/ttycom.h>
#include <termios.h>
#include <unistd.h>

struct termios orig_termios;

// disables raw mode in the terminal by setting some flags
// into the termios struct. stores the original settings
void termEnableRaw() {
  if(tcgetattr(STDIN_FILENO, &orig_termios) == -1)
    die("termEnableRaw -> tcgetattr");

  struct termios raw = orig_termios;

  // switching off some flags
  // ECHO - output the inputed characters
  // ICANON - canonical mode
  // ISIG - Disable SIGINT and SIGTSTP etc?
  // IEXTEN - Enable implementation defined input processing
  // IXON - software flow control (CTRL-S and CTRL-Q)
  // ICRNL - enables translating carriage returns (13) into newlines (10)
  // OPOST - enables post processing output (\n to \r\n)
  raw.c_iflag &= ~(BRKINT | ICRNL | INPCK | ISTRIP | IXON);
  raw.c_oflag &= ~(OPOST);
  raw.c_cflag |= (CS8);
  raw.c_lflag &= ~(ECHO | ICANON | IEXTEN | ISIG);
  raw.c_cc[VMIN] = 0;
  raw.c_cc[VTIME] = 1; 

  if(tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw) == -1)
    die("termEnableRaw -> tcsetattr");
}

void termDisableRaw() {
  if (tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios) == -1)
    die("termDisableRaw -> tcsetattr");
}

int termMoveCrsr(int rows, int cols) {
  termCrsrTopLeft();

  char buf[30];
  snprintf(buf, 30, "\x1b[%dC\x1b[%dB", cols, rows);
  if (write(STDOUT_FILENO, buf, 30) != 30) 
    return -1;
  
  return 0;
}

int termGetCrsrPos(int *rows, int *cols) {
  char buf[128];
  unsigned int i = 0;

  if(write(STDOUT_FILENO, "\x1b[6n", 4) != 4) return -1;

  // reading into buf
  // the response should look like 24;80R,
  // so we need to parse those numbers out
  while(i < sizeof(buf) - 1) {
    if(read(STDIN_FILENO, &buf[i], 1) != 1) break;
    if(buf[i] == 'R') break;
    i++;
  }

  buf[i] = '\0';

  if(buf[0] != '\x1b' || buf[1] != '[') return -1;
  if(sscanf(&buf[2], "%d;%d", rows, cols) != 2) return -1;

  return 0;
}

int termGetWinSize(int *rows, int *cols) {
  struct winsize ws;

  if(ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1 || ws.ws_col == 0) {
    if(termMoveCrsr(999, 999) == -1) return -1;
    return termGetCrsrPos(rows, cols);
  }

  *cols = ws.ws_col;
  *rows = ws.ws_row;
  return 0;
}
