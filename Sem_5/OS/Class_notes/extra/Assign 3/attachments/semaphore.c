#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <semaphore.h>
#define BUFFER_SIZE 100

//const int BUFFER_SIZE = 10;
int PRODUCERS;
int CONSUMERS;
int NUMB_THREADS = 15;
int buffer_index = 0;
//int buffer[BUFFER_SIZE];
struct Item {
    int item_id;
    int producer_id;
    int payload;
}buffer[BUFFER_SIZE];

sem_t E ; // EMPTY
sem_t F ; // FULL
sem_t S ; // Normal

void *producer(void *arg) {
	int id = *(int *)arg;
	int value, pay;
	//int i = 0;
		sleep(rand() % 10);
		value = (rand() % 100);
		sem_wait(&E);
		sem_wait(&S);
		/* CRITICAL SECTION	*/
		if (buffer_index < BUFFER_SIZE) {
        	buffer[buffer_index].producer_id = id;
            buffer[buffer_index].item_id = value;
            buffer[buffer_index].payload = (rand() % 100);
            pay = buffer[buffer_index++].payload;
    	} 
    	else {
        	printf("Buffer overflow\n");
    	}
    	/*	ENDS	*/
    	sem_post(&S);
    	sem_post(&F);
    	printf("Producer %d added : %d%d%d \n", id,value,id,pay);
	pthread_exit(0);
}

void *consumer(void *arg) {
	int id = *(int *)arg;
	int value,prod_id,pay;
	//int i = 0;
		sleep(rand() % 10);
		sem_wait(&F);
		sem_wait(&S);
		if (buffer_index > 0) {
        	value = buffer[--buffer_index].item_id;
            prod_id = buffer[buffer_index].producer_id;
            pay = buffer[buffer_index].payload;
    	} 
    	else {
        	printf("Buffer underflow\n");
    	}
    	sem_post(&S);
    	sem_post(&E);
    	printf("Consumer %d removed :  %d%d%d%d\n", id, value,prod_id,id,pay);
	pthread_exit(0);
}


int main(int argc, char const *argv[]) {
    printf("Enter the Number of Producers and Consumers : ");
    scanf("%d %d",&PRODUCERS,&CONSUMERS);
    NUMB_THREADS = PRODUCERS + CONSUMERS;
	sem_init(&E,0,BUFFER_SIZE);
	sem_init(&F,0,0);
	sem_init(&S,0,1);
	pthread_t thread[NUMB_THREADS];
	int value = 0;
	//int thread_nmb[NUMB_THREADS];
    for(int i = 0; i < NUMB_THREADS; i++) {
    	value = i;
    	pthread_create(thread + i, NULL, producer, &value);
    	i++;
    	value = i;
    	pthread_create(thread + i, NULL, consumer, &value);
    }
    for (int i = 0; i < NUMB_THREADS; i++)
        pthread_join(thread[i], NULL);
    sem_destroy(&E);
    sem_destroy(&F);
   	sem_destroy(&S);
	return 0;
}