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
	int *rc, *wc;
	int r, w;
	int *buffer;
	printf("Enter reader number");
	scanf("%d", &r);
	printf("Enter writer number");
	scanf("%d", &w);
	pid_t pid;
	sem_t *mutex1, *mutex2, *mutex3, *mutex4, *wrt, *rd;
	sem_unlink("/s1");
	mutex1=sem_open("/s1", O_CREAT, 0644, 1);
	sem_unlink("/s2"); 
	wrt=sem_open("/s2", O_CREAT, 0644, 1);
	sem_unlink("/s3");
	rd=sem_open("/s3", O_CREAT, 0644, 1);
	sem_unlink("/s4");
	mutex2=sem_open("/s4", O_CREAT, 0644, 1);
	sem_unlink("/s5");
	mutex3=sem_open("/s5", O_CREAT, 0644, 1);
	sem_unlink("/s6");
	mutex4=sem_open("/s6", O_CREAT, 0644, 1);
	
	buffer = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	rc = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	wc = (int*)mmap(NULL,sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    *rc = 0;
	*wc = 0;
	*buffer = -1;
	pid = fork();

	if(pid < 0)
	{
		printf("Fork error\n");
	}
	else if(pid == 0)
	{
		srand(time(0));
		for(int i = 0; i < w; i++)
		{
			
			if(fork() == 0)
			{
				sleep(1);
				sem_wait(mutex1);
				*wc = *wc + 1;
				if(*wc == 1)
				{
					sem_wait(rd);
				}
				sem_post(mutex1);

				sem_wait(wrt);
				*buffer=rand()%10;
				printf("Data written by writer %d is %d\n", i, i+1);
				*buffer= i + 1;
				sem_post(wrt);
				sem_wait(mutex2);
				*wc = *wc - 1;
				if(*wc == 0)
				{
					sem_post(rd);
				}
				sem_post(mutex2);
				exit(1);
		    }

		}
		for(int i = 0; i < w; i++)
	        wait(NULL);
        exit(1);
	}
	else
	{
		sleep(1);
		for(int i = 0; i < r; i++)
		{
			if(fork() == 0)
			{
				sem_wait(rd);
				sem_wait(mutex3);
				*rc = *rc + 1;
				if(*rc == 1)
				{
					sem_wait(wrt);
				}
				sem_post(mutex3);
				sem_post(rd);
				printf("Data read by the reader %d is %d\n", i, *buffer);
				sem_wait(mutex4);
				*rc = *rc - 1;
				if(*rc == 0)
				sem_post(wrt);
				sem_post(mutex4);
				exit(1);
			}
			else
				wait(NULL);
			
		}
        	
	}
	wait(NULL);
	sem_close(mutex1);
    sem_unlink("/s1");
    
	sem_close(wrt);
    sem_unlink("/s2");
    
	sem_close(rd);
    sem_unlink("/s3");
    
	sem_close(mutex2);
    sem_unlink("/s4");
    
	sem_close(mutex3);
    sem_unlink("/s5");
    
	sem_close(mutex4);
    sem_unlink("/s6");
    return 0;
    
}
