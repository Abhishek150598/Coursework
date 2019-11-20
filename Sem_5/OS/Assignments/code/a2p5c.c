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
        fd1 = open(myfifo,O_RDONLY); 
        read(fd1, str1, 80); 
        if(strcmp(str1,"bye")==0 || strcmp(str1,"BYE")==0)
        {
            close(fd1);
            break;
        }
        printf("user2: %s\n", str1); 
        close(fd1); 
        fd1 = open(myfifo,O_WRONLY);
        printf("user1:");
        fgets(str2, 80, stdin); 
        write(fd1, str2, strlen(str2)+1); 
        close(fd1); 
    } 
    return 0; 
} 