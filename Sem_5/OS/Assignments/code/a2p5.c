#include <stdio.h> 
#include <unistd.h>
#include<stdlib.h>
#include<string.h>
#include <stdio.h>
#include <string.h>
#include<stdlib.h>
#include<time.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
int main()
{
    char a[100]="Hello world";
    char b[100];
    int x;
    printf("enter recever number: ");
    scanf("%d",&x);
    int p[2];
    if(pipe(p)<0)
    {

    }
    pid_t pid;
    pid=fork();
    if(pid<0)
    {

    }
    else if(pid == 0)
    {
        write(p[1], a, strlen(a));
    }
    else
    {
        wait(NULL);
        int y = read(p[0], b, strlen(a) + 1);
        for(int i = 0; i < x; i++)
        {
            if(!fork())
            {
                printf("Listener %d reads %s\n",i,b);
                exit(2);
            }
            
        }
        for(int i=0;i<x;i++)
            wait(NULL);
        printf("Finished reading\n");

    }
     wait(NULL);

}
