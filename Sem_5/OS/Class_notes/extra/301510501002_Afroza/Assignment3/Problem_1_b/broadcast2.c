#include <fcntl.h>
#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#define MAX_BUF 1024

int main()
{
    int fd;
    char *myfifo = "/tmp/myfifo2";
    char buf[MAX_BUF];

    /* open, read, and display the message from the FIFO */
    fd = open(myfifo, O_RDONLY);
    while(1){
    	read(fd, buf, MAX_BUF);
    	if(strcmp(buf,"Quit")==0){
    		close(fd);
    		return 0;
    	}
    	printf("Received: %s\n", buf);
    }

    return 0;
}
