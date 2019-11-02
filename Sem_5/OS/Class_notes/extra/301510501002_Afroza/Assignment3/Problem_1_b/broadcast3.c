#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
    int fd, fd1;
    char *myfifo = "/tmp/myfifo";
    char *myfifo2 = "/tmp/myfifo2";
    char str[100];

    mkfifo(myfifo, 0666);
    mkfifo(myfifo2, 0666);

    fd = open(myfifo, O_WRONLY);
    fd1 = open(myfifo2, O_WRONLY);
    
    while(1){
    	printf("Write: ");
    	scanf(" %s",str);
    	write(fd, str, sizeof(str));
    	write(fd1, str, sizeof(str));
    	if(strcmp(str,"Quit")==0){
    		close(fd);
    		close(fd1);
    		/* remove the FIFO */
    		unlink(myfifo);
    		unlink(myfifo2);
    		return 0;
    	}
    }

    return 0;
}
