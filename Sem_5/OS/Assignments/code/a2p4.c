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

int *buffer, *readcnt, *writecnt;
sem_t *rmutex, *wmutex, *rd, *wrt;

void writer_process(int i, int val)
{
	sem_wait(wmutex);
	// Section for incrementing write count
	*writecnt += 1;
	if(*writecnt == 1)
		sem_wait(rd); // Block readers
	sem_post(wmutex);

	sem_wait(wrt);
	// Critical section
	*buffer = val;
	printf("Writer %d wrote value %d\n", i, *buffer);
	sem_post(wrt);

	sem_wait(wmutex);
	// Section for decrementing write count
	*writecnt -= 1;
	if(*writecnt == 0)
		sem_post(rd); // Enable readers
	sem_post(wmutex);
}

void reader_process(int i)
{
	sem_wait(rd); // Permission to attempt read
	sem_wait(rmutex);
	// Section for incrementing read count
	*readcnt += 1;
	if(*readcnt == 1)
		sem_wait(wrt); // Block writers
	sem_post(rmutex);
	sem_post(rd);

	printf("Reader %d read value %d\n", i, *buffer);

	sem_wait(rmutex);
	// Section for decrementing read count
	*readcnt -= 1;
	if(*readcnt == 0)
		sem_post(wrt); // Enable writers
	sem_post(rmutex);
}


int main()
{
	int readers, writers;
	srand(time(NULL)); 

	sem_unlink("/s1");
	rmutex = sem_open("/s1", O_CREAT, 0644, 1);
	sem_unlink("/s2");
	wmutex = sem_open("/s2", O_CREAT, 0644, 1);
	sem_unlink("/s3");
	rd = sem_open("/s3", O_CREAT, 0644, 1);
	sem_unlink("/s4");
	wrt = sem_open("/s4", O_CREAT, 0644, 1);

	printf("Enter the number of readers: ");
	scanf("%d", &readers);

	printf("Enter the numbe of writers: ");
	scanf("%d", &writers);

	buffer = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	readcnt = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
	writecnt = (int*)mmap(NULL, sizeof(int), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

	pid_t pid = fork();

	if(pid < 0)
	{
		printf("Fork error");
		exit(0);
	}
	else if(pid == 0)
	{
		
		for(int i = 0; i < writers; i++)
		{
			int val = rand() % 50;
			pid_t p = fork();
			if(p < 0)
			{
				printf("Fork error\n");
				exit(0);
			}
			else if(p == 0)
			{
				//int val = rand() % 50;
				writer_process(i, val);
				exit(1);
			}
		}
		for(int i = 0; i < writers; i++)
			wait(NULL);
		exit(1);

	}
	else
	{
		
		sleep(1);
		for(int i = 0; i < readers; i++)
		{
			pid_t p = fork();
			if(p < 0)
			{
				printf("Fork error\n");
				exit(0);
			}
			else if(p == 0)
			{
				reader_process(i);
				exit(1);
			}
			else
				wait(NULL);
		}
	}
	wait(NULL);

	sem_close(rmutex);
	sem_unlink("/s1");
	sem_close(wmutex);
	sem_unlink("/s2");
	sem_close(rd);
	sem_unlink("/s3");
	sem_close(wrt);
	sem_unlink("/s4");

}