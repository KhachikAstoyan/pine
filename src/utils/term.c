#include "term.h"
#include "err.h"
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

