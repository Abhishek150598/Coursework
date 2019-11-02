#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <sys/wait.h>
#include <fcntl.h>
#define MAXBUFFERLENGTH 30

int *shared_buffer, *head, *tail, *counter, *producers_left; //shared memory variables
/*semaphores*/
sem_t *mutex;
sem_t *full;
sem_t *empty;
sem_t *producers_count;

int buffer_empty(){

	return(*counter==0);
}
int buffer_full(){

	return(*counter==MAXBUFFERLENGTH);
}
void add_element(int ele){

	if(buffer_full()){

		printf("Buffer full, can't add item\n");
		return;
	}
	shared_buffer[*tail]=ele;
	*counter=*counter+1;
	*tail=(*tail+1)%MAXBUFFERLENGTH;
}
int remove_element(){

	if(buffer_empty()){
		printf("Buffer empty, no item to remove\n");
		return 0;
	}
	int ele=shared_buffer[*head];
	*head=(*head+1)%MAXBUFFERLENGTH;
	*counter=*counter-1;
	return ele;
}
int main(){


	int n_producer, n_consumer,i;
	pid_t producers[10];
	pid_t consumers[10];
	/*Initialize shared  memory variables*/
	shared_buffer=(int*)mmap(NULL, MAXBUFFERLENGTH*sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	head=(int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	tail=(int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	counter=(int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	producers_left=(int*)mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0);
	if(shared_buffer==MAP_FAILED || head==MAP_FAILED || tail==MAP_FAILED || counter==MAP_FAILED || producers_left==MAP_FAILED){

		printf("Error in assigning shared memory\n");
		exit(EXIT_FAILURE);
	}
	*counter=0; //no item;
	*head=*tail=0;
	/*open semaphores*/
	sem_unlink("MUTEX");
	sem_unlink("FULL");
	sem_unlink("EMPTY");
	sem_unlink("PRODUCER_COUNT");
	mutex=sem_open("MUTEX", O_CREAT, S_IRUSR|S_IWUSR, 1);
	empty=sem_open("EMPTY", O_CREAT, S_IRUSR|S_IWUSR, MAXBUFFERLENGTH);
	full=sem_open("FULL", O_CREAT, S_IRUSR|S_IWUSR, 0);
	producers_count=sem_open("PRODUCER_COUNT", O_CREAT, S_IRUSR|S_IWUSR, 1);
	if(mutex==SEM_FAILED || empty==SEM_FAILED || full==SEM_FAILED || producers_count==SEM_FAILED){

		printf("Error in creating semaphore(s)\n");
		exit(EXIT_FAILURE);
	}
	printf("Enter no. of producers and consumers: ");
	scanf("%d %d",&n_producer, &n_consumer);
	*producers_left=n_producer;
	for(i=0;i<n_consumer;i++){

		consumers[i]=fork();
		printf("Consumer %d created with process id %d\n", i,consumers[i]);
		if(consumers[i]<0){

			printf("Error in fork\n");
			exit(EXIT_FAILURE);
		}
		if(consumers[i]==0){

			
			while(1){
				
				sem_wait(full);
				sem_wait(mutex);
				if(buffer_empty()){
					
					sem_post(mutex);
					sem_post(full);
					break;

				}
				int ele=remove_element();
				printf("Consumer %d received item: %d\n",i,ele);
				sem_post(mutex);
				sem_post(empty);
			}
			printf("Exited consumer %d\n",i);
			exit(EXIT_SUCCESS);
		}	
	}
	for(i=0;i<n_producer;i++){
		
		producers[i]=fork();
		printf("Producer %d created with process id %d\n",i, producers[i]);
		if(producers[i]<0){

			printf("Error in fork\n");
			exit(EXIT_FAILURE);
		}
		if(producers[i]==0){
			
			for(int j=0;j<5;j++){

				sem_wait(empty);
				sem_wait(mutex);
				printf("Producer %d produced item: %d\n",i,j);
				add_element(j);
				sem_post(mutex);
				sem_post(full);
			}
			printf("Exited producer %d\n",i);
			/*if all producers exited, the signal all consumers to exit*/
			sem_wait(producers_count);
			*producers_left=*producers_left-1;
			if(*producers_left==0){
				for(int j=0;j<n_consumer;j++)
					sem_post(full);
			}
			sem_post(producers_count);
			exit(EXIT_SUCCESS);
		}
	}	
	int status;
	pid_t pi;
	for(i=0;i<n_producer+n_consumer;i++){

		pi=wait(&status);
		if(pi<0)
			printf("Process %d exited\n", pi);
	}
	sem_unlink("MUTEX");
	sem_unlink("FULL");
	sem_unlink("EMPTY");
	sem_unlink("PRODUCER_COUNT");
	return 0;
}