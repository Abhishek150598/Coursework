#include <fcntl.h>
#include <iostream>
#include <sys/stat.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#define MAX_BUF 1024

using namespace std;

int main()
{
    int fd1,fd2;
    
    char snd[MAX_BUF];
    char buf[MAX_BUF];
    char * mysnd = "/tmp/mypipe1";
    char * myrcv = "/tmp/mypipe2";
    
    mkfifo(mysnd, 0666);
    fd1 = open(mysnd, O_WRONLY);
    fd2 = open(myrcv, O_RDONLY);

    /* create the (named pipe) */
    while(strcmp(snd,"quit"))
    {
    	printf("\nSend:");
	cin.getline(snd,MAX_BUF);
    	write(fd1, snd, sizeof(snd));
    	
    	read(fd2, buf, MAX_BUF);
    	printf("\nReceived: %s\n", buf);
    	
    }
	
	close(fd1);
	close(fd2);
	/* remove the FIFO */
    	unlink(mysnd);
    return 0;
}


