#include <sys/types.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <sys/wait.h>

#include <sys/shm.h>


#include <fcntl.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

#define PRIORITY_GUARD		"/PRIORITY_GUARD"
#define READ_COUNT_GUARD	"/READ_COUNT_GUARD"
#define WRITE_COUNT_GUARD	"/WRITE_COUNT_GUARD"
#define READ_GUARD			"/READ_GUARD"
#define WRITE_GUARD			"/WRITE_GUARD"



#define SKEY 0xABCD


void writer(int index) {

	/* General semaphore initialisation */
	sem_t *R_GUARD 	= sem_open(READ_COUNT_GUARD, O_RDWR);
	sem_t *W_GUARD 	= sem_open(WRITE_COUNT_GUARD, O_RDWR);
	sem_t *PR_GUARD = sem_open(PRIORITY_GUARD, O_RDWR);
	sem_t *WC_GUARD = sem_open(WRITE_GUARD, O_RDWR);
	sem_t *RC_GUARD = sem_open(READ_GUARD, O_RDWR);


	/* General shared memory initialisation */
	key_t shm_key 		= SKEY;
    const int shm_size 	= (2)*sizeof(int);
    int shm_id 			= shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
    int *shm_addr 		= (int *)shmat(shm_id, 0, 0);
	int *readcount 		= shm_addr, *writecount = shm_addr + sizeof(int);

	while(1) {
		sleep(1);

		sem_wait(W_GUARD);

		*writecount = *writecount + 1;
		if(*writecount == 1)
			sem_wait(RC_GUARD);

		sem_post(W_GUARD);



		sem_wait(WC_GUARD);

		printf("Waiting Readers: %d, Waiting Writers: %d\n", *readcount, *writecount - 1);

		printf("Writer %d is writing\n", index);
		printf("Writer %d has completed task.\n", index);

		printf("\n");

		sem_post(WC_GUARD);


		sem_wait(W_GUARD);

		*writecount = *writecount - 1;
		if(*writecount == 0)
			sem_post(RC_GUARD);

		sem_post(W_GUARD);
	}
}

void reader(int index) {

	/* General semaphore initialisation */
	sem_t *R_GUARD 	= sem_open(READ_COUNT_GUARD, O_RDWR);
	sem_t *W_GUARD 	= sem_open(WRITE_COUNT_GUARD, O_RDWR);
	sem_t *PR_GUARD = sem_open(PRIORITY_GUARD, O_RDWR);
	sem_t *WC_GUARD = sem_open(WRITE_GUARD, O_RDWR);
	sem_t *RC_GUARD = sem_open(READ_GUARD, O_RDWR);


	/* General shared memory initialisation */
	key_t shm_key 		= SKEY;
    const int shm_size 	= (2)*sizeof(int);
    int shm_id 			= shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
    int *shm_addr 		= (int *)shmat(shm_id, 0, 0);
	int *readcount 		= shm_addr, *writecount = shm_addr + sizeof(int);

	while(1) {
		sleep(1);

		sem_wait(PR_GUARD);
		sem_wait(RC_GUARD);
		sem_wait(R_GUARD);

		*readcount = *readcount + 1;
		if(*readcount == 1)
			sem_wait(WC_GUARD);

		sem_post(R_GUARD);
		sem_post(RC_GUARD);

		sem_post(PR_GUARD);

		printf("Waiting Readers: %d, Waiting Writers: %d\n", *readcount - 1, *writecount);

		printf("Reader %d is reading\n", index);
		printf("Reader %d completed task.\n", index);
		printf("\n");

		sem_wait(R_GUARD);

		*readcount = *readcount - 1;
		if(*readcount == 0)
			sem_post(WC_GUARD);

		sem_post(R_GUARD);
	}
}


int main() {
	int readers, writers;

	printf("Number of readers : ");
	scanf("%d", &readers);

	printf("Number of writers : ");
	scanf("%d", &writers);

	key_t shm_key 		= SKEY;
    const int shm_size 	= (2)*sizeof(int);
    int shm_id 			= shmget (shm_key, shm_size, IPC_CREAT | S_IRUSR | S_IWUSR);
    int *shm_addr 		= (int *)shmat(shm_id, 0, 0);
    int *readcount 		= shm_addr, *writecount = shm_addr + sizeof(int);

    *readcount = 0;
    *writecount = 0;

	/* General semaphore initialisation */
    sem_t *R_GUARD 	= sem_open(READ_COUNT_GUARD, 	O_CREAT, (S_IRUSR | S_IWUSR), 1);
    sem_t *W_GUARD 	= sem_open(WRITE_COUNT_GUARD, 	O_CREAT, (S_IRUSR | S_IWUSR), 1);
    sem_t *PR_GUARD = sem_open(PRIORITY_GUARD, 		O_CREAT, (S_IRUSR | S_IWUSR), 1);
    sem_t *WC_GUARD = sem_open(WRITE_GUARD, 		O_CREAT, (S_IRUSR | S_IWUSR), 1);
    sem_t *RC_GUARD = sem_open(READ_GUARD, 			O_CREAT, (S_IRUSR | S_IWUSR), 1);

    pid_t wr[writers], rd[readers];

	/* Create Writers */

   	for(int i = 0; i < writers; ++i) {
   		wr[i] = fork();
   		if(wr[i] < 0)
   			exit(0);
   		else if(wr[i] == 0) {
   			writer(i);
   			exit(0);
   		}
   	}

	/* Create Readers */

    for(int i = 0; i < readers; ++i) {
    	rd[i] = fork();
    	if(rd[i] < 0)
    		exit(0);
    	else if(rd[i] == 0) {
    		reader(i);
    		exit(0);
    	}
    }

    int status, total_child_processes = writers + readers;
	pid_t pid;
	while(total_child_processes > 0) {
 		pid = wait(&status);
		--total_child_processes;
	}

	/* Clear */

    shm_unlink(READ_COUNT_GUARD);
    shm_unlink(WRITE_COUNT_GUARD);
    shm_unlink(PRIORITY_GUARD);
    shm_unlink(WRITE_GUARD);
    shm_unlink(READ_GUARD);

  	return 0;
}
