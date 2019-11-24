#include <stdio.h> 
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main()
{
	int r;
	char temp;
	char str1[100], str2[100];
	printf("Enter number of receivers:");
	scanf("%d", &r);
	printf("Enter information to be broadcasted:\n");
	scanf("%c",&temp);
	scanf("%[^\n]", str1);

	int p[2];

	if(pipe(p) < 0)
	{
		printf("Pipe error");
		exit(0);
	}

	pid_t pid;
	pid = fork();

	if(pid < 0)
	{
		printf("Fork error");
		exit(0);
	}
	else if(pid == 0)
	{
		// Broadcasting process
		write(p[1], str1, strlen(str1));
		printf("Message broadcasted\n");
	}
	else
	{
		wait(NULL);
		int y = read(p[0], str2, strlen(str1) + 1);
		for(int i = 0; i < r; i++)
		{
			// Receiving process 
			if(!fork())
			{
				printf("Message received by receiver %d: %s\n", i, str2);
				exit(2);
			}

		}
		for(int i = 0; i < r; i++)
			wait(NULL);
	}
	wait(NULL);

}