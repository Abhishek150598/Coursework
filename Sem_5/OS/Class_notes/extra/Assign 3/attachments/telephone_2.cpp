#include <fcntl.h>
#include <sys/stat.h>
#include <iostream>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string.h>
#define MAX_BUF 1024

using namespace std;

int main()
{
    int fd1,fd2;
    
    char snd[MAX_BUF];
    char buf[MAX_BUF];
    char * mysnd = "/tmp/mypipe2";
    char * myrcv = "/tmp/mypipe1";
    
    fd2 = open(myrcv, O_RDONLY);
    mkfifo(mysnd, 0667);
    fd1 = open(mysnd, O_WRONLY);
    

    /* create the (named pipe) */
    while(strcmp(snd,"quit"))
    {
    	
    	
    	read(fd2, buf, MAX_BUF);
    	printf("\nReceived: %s\n", buf);
    	
    	
    	printf("\nSend:");
    	cin.getline(snd,MAX_BUF);
    	write(fd1, snd, sizeof(snd));
    	
    	
    }
    close(fd2);
    close(fd1);
    unlink(mysnd);

    return 0;
}
