/*Attempt to solve the multiple reader writer problem.
*Conditions to be met are as follows:
*--no reader shall wait if it is opened for reading
*--no writer added to the queue should be waiting for more than necessary
*/
#include <stdio.h>
#include <pthread.h>
#include <math.h>

char active_thread_type;
int write_request;

pthread_mutex_t mymutex;

void* reader(void* t_data){
	printf("\nreader Created");
	int* this_val=(int*)t_data;
	while(active_thread_type=='w' || write_request>0);
	pthread_mutex_lock(&mymutex);
	active_thread_type='r';
	pthread_mutex_unlock(&mymutex);
	printf("\nAccessed by reader. Current value of resource is- %d",*this_val);
	pthread_mutex_lock(&mymutex);
	active_thread_type='n';
	pthread_mutex_unlock(&mymutex);
	pthread_exit(NULL);
}
void* writer(void* t_data){
	printf("\nWriter created");
	write_request++;
	int *this_val=(int*)t_data;
	int r;
	r=rand()%10;
	while(active_thread_type=='r');
	//Critical Section
	pthread_mutex_lock(&mymutex);
	write_request--;
	active_thread_type='w';
	*this_val=r;
	printf("\nAccessed by writer. Current value of buffer is- %d",*this_val);
	active_thread_type='n';
	pthread_mutex_unlock(&mymutex);
	pthread_exit(NULL);
}
int main(){
	int r,rval,val=0,total=0;
	pthread_mutex_init(&mymutex,NULL);
	write_request=0;
	active_thread_type='n';
	while(1){
		pthread_t thrd;
		r=rand()%2;
		if(r){
			rval=pthread_create(&thrd,NULL,reader,(void *)&val);
		}else{
			rval=pthread_create(&thrd,NULL,writer,(void *)&val);
		}
		if (rval){
        		 printf("ERROR; return code from pthread_create() is %d\n", rval);
         		return 1;
      		}else
			total++;
		if(total>5){
			sleep(1);
			total=0;
		}
	}
	pthread_mutex_destroy(&mymutex);
}
