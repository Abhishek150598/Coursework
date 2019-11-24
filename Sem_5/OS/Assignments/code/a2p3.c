#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#define CIRCULAR_SIZE 25

static int *cqueue;
static int *in;
static int *out;
static int *ans;
static int *verify;
sem_t *empty;
sem_t *full;
sem_t *mutex;
sem_t *mutex_consumer;


int item()
{
    return rand()%80;
}

void create_producer(int index)
{
    int pid=fork();

    if(pid == 0)
    {
        for(int i = 0; i < 10; i++)
        {
            sem_wait(empty);
            sem_wait(mutex);

            cqueue[*in]=item();
            printf("Produced by %d producer %d\n",index,cqueue[*in]);
            *verify += cqueue[*in];
            *in=(*in + 1) % CIRCULAR_SIZE;

            sem_post(mutex);
            sem_post(full);
        }
        printf("Production finished of producer %d\n",index );
        exit(1);
    }
    
    

}
void create_consumer(int index)
{
    int pid=fork();
    if(pid == 0)
    {
        while(1)
        {
            
            sem_wait(full);
            sem_wait(mutex);

            if(*in == *out)
            {
                sem_post(mutex);
                sem_post(full);
                break;   
            }

            int consumed = cqueue[*out];
            *out = (*out + 1) % CIRCULAR_SIZE;
            
            sem_post(mutex);
            sem_post(empty);

            sem_wait(mutex_consumer);
            *ans = *ans + consumed;
            printf("Consumed %d by consumer %d\n", consumed, index);
            sem_post(mutex_consumer);
        }
        printf("Consumption finished of consumer %d\n",index );
        exit(1);
    }

    
}
int main()
{	
    int pid;
    
	cqueue = mmap(NULL, 25 * sizeof (cqueue), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    in = mmap(NULL, sizeof *in, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    out = mmap(NULL, sizeof *out, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);  
    ans = mmap(NULL, sizeof *ans, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    verify = mmap(NULL, sizeof *verify, PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);
    
    sem_unlink("/semaphore1");
    full = sem_open("/semaphore1", O_CREAT, 0644, 0);
    sem_unlink("/semaphore2");
    empty = sem_open("/semaphore2", O_CREAT, 0644, CIRCULAR_SIZE - 1);
    sem_unlink("/semaphore3");
    mutex = sem_open("/semaphore3", O_CREAT, 0644, 1);
    sem_unlink("/semaphore4");
    mutex_consumer = sem_open("/semaphore4", O_CREAT, 0644, 1);
    
    *in = 0, *out = 0;

	for(int i = 0; i < 10; i++)
       cqueue[i]=0;

    int p,c;
    printf("Enter number of producers and consumers:\n");
    scanf("%d %d", &p, &c);
    pid = fork();
    
	if(pid < 0)
        printf("Fork error\n");
    else if(pid == 0)
    {
    	//Producer
    	for(int i = 0; i < p; i++)
        {
            create_producer(i);   
        }
        for(int i = 0; i < p; i++)
            wait(NULL);
    	for(int i = 0; i < c; i++)
            sem_post(full);
        exit(0);
    }
    else
    {  
    	//Consumer
    	for(int i = 0; i < c; i++)
        {
            create_consumer(i);   
        }
        for(int i = 0; i < c; i++)
            wait(NULL);
    }
    wait(NULL);    

    printf("Total %d\n",  *ans);
    printf("Verify %d\n", *verify);
    sem_close(full);
    sem_unlink("/semaphore1");
    sem_close(empty);
    sem_unlink("/semaphore2");
    sem_close(mutex);
    sem_unlink("/semaphore3");
    sem_close(mutex_consumer);
    sem_unlink("/semaphore4");
    return 0;
}