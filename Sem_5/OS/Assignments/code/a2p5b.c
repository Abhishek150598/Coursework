
#include <stdio.h> 
#include <string.h> 
#include <fcntl.h> 
#include <sys/stat.h> 
#include <sys/types.h> 
#include <unistd.h> 
  
int main() 
{ 
    int fd; 
    char* myfifo = "myfifo"; 
    mkfifo(myfifo, 0640); 
    char arr1[80], arr2[80]; 
    while (1) 
    { 
        fd = open(myfifo, O_WRONLY); 
        printf("user2:");
        fgets(arr2, 80, stdin); 
        if(strcmp(arr2,"bye")==0 || strcmp(arr2,"BYE")==0)
        {
            close(fd);
            break;
        }
        write(fd, arr2, strlen(arr2)+1); 
        close(fd); 
        fd = open(myfifo, O_RDONLY); 
        read(fd, arr1, sizeof(arr1)); 
        printf("user1: %s\n", arr1); 
        close(fd); 
    } 
    return 0; 
} 
