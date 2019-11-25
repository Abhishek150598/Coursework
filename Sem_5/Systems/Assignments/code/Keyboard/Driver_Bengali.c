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

void get_bangali(char c)
{
	if(c=='a'|| c=='A') printf("অ");
	if(c=='b'|| c=='B') printf("ব");
	if(c=='c'|| c=='C') printf("স");
	if(c=='d'|| c=='D') printf("ড");
	if(c=='e'|| c=='E') printf("ই");
	if(c=='f'|| c=='F') printf("ফ");
	if(c=='g'|| c=='G') printf("গ");
	if(c=='h'|| c=='H') printf("হ");
	if(c=='i'|| c=='I') printf("আ");
	if(c=='j'|| c=='J') printf("জ");
	if(c=='k'|| c=='K') printf("ক");
	if(c=='l'|| c=='L') printf("ল");
	if(c=='m'|| c=='M') printf("ম");
	if(c=='n'|| c=='N') printf("ন");
	if(c=='o'|| c=='O') printf("ও");
	if(c=='p'|| c=='P') printf("প");
	if(c=='q'|| c=='Q') printf("খ");
	if(c=='r'|| c=='R') printf("র");
	if(c=='s'|| c=='S') printf("স");
	if(c=='t'|| c=='T') printf("ট");
	if(c=='u'|| c=='U') printf("ইউ");
	if(c=='v'|| c=='V') printf("ভ");
	if(c=='w'|| c=='W') printf("ড");
	if(c=='x'|| c=='X') printf("একস");
	if(c=='y'|| c=='Y') printf("ওআই");
	if(c=='z'|| c=='Z') printf("জেড");
	fflush(stdout);
  //printf("\n");
}


int main(){
    enableRawMode();
    
    char c;
        
    
    while (read(STDIN_FILENO, &c, 1) == 1 && c != 'q'){
      if (iscntrl(c)) {
       printf("\n");}
      else {
        get_bangali(c);
        
      }
    }
    
    return 0;
}