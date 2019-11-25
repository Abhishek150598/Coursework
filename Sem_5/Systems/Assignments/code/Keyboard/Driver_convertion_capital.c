#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include<string.h>


struct termios orig_termios;

void disableRawMode() {
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &orig_termios);
}

void enableRawMode() {
  tcgetattr(STDIN_FILENO, &orig_termios);
  atexit(disableRawMode);

  struct termios raw = orig_termios;
  raw.c_lflag &= ~(ECHO | ICANON);
  tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}


char conver(char s)
{
	char s_cap;
	int len;
	if(s>='a' && s<='z')
		{
			s_cap=s - 32;
		}
		else
		{
			s_cap=s;
		}
	return s_cap;
}

int main(){
    enableRawMode();
    
    char c;
        
    
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){
      if (iscntrl(c)) {
       printf("\n");}
      else {
        printf("%c",conver(c));
        fflush(stdout);
      }
    }
    
    return 0;
}