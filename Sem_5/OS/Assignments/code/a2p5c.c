// User 2
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd1; 
    char * myfifo = "myfifo"; 
    mkfifo(myfifo, 0640); 
    char str1[80], str2[80]; 
    while (1) 
    {  
        // Opening the FIFO for reading
        fd1 = open(myfifo, O_RDONLY); 
        read(fd1, str1, 80); 
        printf("User_1: %s\n", str1); 
        close(fd1); 

        if(strcmp(str1,"bye")==0 || strcmp(str1,"BYE")==0)
            break;

        // Opening the FIFO for writing
        fd1 = open(myfifo, O_WRONLY);
        printf("User_2:");
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0; 
} 
