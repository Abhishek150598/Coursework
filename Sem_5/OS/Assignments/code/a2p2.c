#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

int main()
{
    pid_t pid;
    int i;

    pid = fork();

    if(pid < 0)
    {
        perror("Fork failed\n");
        return 1;
    }
    else if(pid == 0)
    {
        for(i = 1; i <= 10; i++)
        {
            usleep(3000);
            printf("Process X- %d\n", i);
        }
        printf("Process X completed\n");
        exit(0);
    }
    else
    {
        if(!fork())
        {
            for(i = 1; i <= 10; i++)
            {
                usleep(3000);
                printf("Process Y- %d\n", i);
            }
            printf("Process Y completed\n");
            exit(0);
        }
        wait(NULL);
        wait(NULL);
    }

    return 0;
}

