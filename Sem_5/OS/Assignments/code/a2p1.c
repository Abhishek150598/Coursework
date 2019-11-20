#include <stdio.h>
#include <stdlib.h>
#define HEAP_CAPACITY 100
#define QUEUE_SIZE 100
#define TIME_QUANTUM 20

typedef struct job
{
	int job_id;
	int priority;
	int arr_time;
	int timing[100];
	int curr;
	int end_time_index;
	int total_burst;
	int round_time;
}job_info;

typedef struct queue_job
{
	job_info* job_queue[QUEUE_SIZE];
	int front;
	int rear;
}queue;

int total_jobs;
job_info* jobs[100];

int heap_size=-1;

// Function to take input from jobs.txt file
void input(void) 
{
	FILE *fp;
	int job_no=0;
	fp=fopen("jobs.txt", "r");
	if(fp == NULL)
	{
		printf("File not found\n");
		exit(0);
	}
	while(!feof(fp))
	{
		int jobid= -1;
		int priority;
		int arr_time;
		int time;
		int time_index = -1;
		fscanf(fp,"%d %d %d %d", &jobid, &priority, &arr_time, &time);
		if(jobid == -1) //to handle space after the last input
			break;
		job_info *job;
		job=(job_info*)malloc(sizeof(job_info));
		job->job_id = jobid;
		job->priority = priority;
		job->arr_time = arr_time;
		int burst = 0;
		while(time != -1)
		{
			time_index++;
			job->timing[time_index] = time;
			burst += time;
			fscanf(fp, "%d", &time);
		}
		job->end_time_index= time_index;
		job->total_burst = burst;
		job->curr = 0;
		job->round_time = 0;
		jobs[job_no] = job;
		job_no++;
	}
	total_jobs = job_no;
	fclose(fp);
}

//Function to sort jobs according to arrival time
void sort_arrival(void) 
{
	for(int i = 0; i < total_jobs - 1; i++)
	{
		int flag = 0;
		for(int j = 0; j < total_jobs - i - 1; j++)
		{
			int arr1 = jobs[j]->arr_time;
			int arr2 = jobs[j+1]->arr_time;
			if(arr1 > arr2)
			{
				flag = 1;
				job_info *job = jobs[j];
				jobs[j] = jobs[j+1];
				jobs[j+1] = job;
			}
		}
		if(flag == 0)
			return;
	}
}

// Function to perform First Come First Served scheduling algorithm
void FCFS(void)
{
	printf("..............FCFS.............\n");
	int i = 0;
	int turn_around_time = 0;
	int waiting_time = 0;
	int timer = jobs[0]->arr_time;
	while(i < total_jobs)
	{
		// CPU Stall
		if(timer < jobs[i]->arr_time)
			timer++;
		// Performing the current job
		else
		{
			printf("t = %d Job ID = %d\n", timer, jobs[i]->job_id);
			timer += jobs[i]->total_burst;
			int local_tat = timer - jobs[i]->arr_time;
			turn_around_time += local_tat;
			waiting_time += local_tat-jobs[i]->total_burst;
			i++;
		}
	}
	// Calculating the average turn around and waiting time
	float avg_tat = (float)turn_around_time / total_jobs;
	float avg_waiting_time = (float)waiting_time / total_jobs;
	
	// Printing the average turn around and waiting time
	printf("Average Turn around time = %f\n", avg_tat);
	printf("Average Waiting time = %f\n", avg_waiting_time);
}

// Function to insert job in priority queue
void insert_heap(job_info* p_queue[],job_info* job)
{
	if(heap_size>HEAP_CAPACITY)
	{
		printf("Heap overflow...exiting\n");
		exit(0);
	}
	heap_size++;
	p_queue[heap_size]=job;
	if(heap_size==0)
		return;
	int p1=job->priority;
	int i=(heap_size-1)/2;
	int p2=jobs[i]->priority;
	int j=heap_size;
	while(i>=0 && p2>p1)
	{
		job_info* temp = p_queue[j];
		p_queue[j] = p_queue[i];
		p_queue[i] = temp;
		j = i;
		i=(i-1)/2;
		if(i<0)
			return;
		p1=p_queue[j]->priority;
		p2=p_queue[i]->priority;
	}
}

// Function to check whether priority queue is empty
int isEmpty(job_info* p_queue[])
{
	if(heap_size == -1)
		return 1;
	return 0;
}

// Function to extract the front element of the priority queue
job_info* extract_root(job_info* p_queue[])
{
	if(heap_size == -1)
		return NULL;
	if(heap_size == 0)
	{
		heap_size--;
		return p_queue[0];
	}

	job_info* root = p_queue[0];
	p_queue[0]=p_queue[heap_size];
	heap_size--;
	int i=0;
	while(i <= heap_size)
	{
		int first = 2*i + 1;
		int second = 2*i + 2;
		job_info* min = p_queue[i];
		if(first <= heap_size)
		{
			if(p_queue[first]->priority < min->priority)
			{
				min = p_queue[first];
				i=first;
			}
		}
		if(second <= heap_size)
		{
			if(p_queue[second]->priority < min->priority)
			{
				min = p_queue[second];
				i=second;
			}
		}

		if(i!=first && i!=second)
			break;

	}
	return root;
}

// Function to perform priority scheduling algorithm
void priority()
{
	printf("............Priority.............\n");
	int turn_around_time = 0;
	int waiting_time = 0;
	int count = 0;
	job_info* p_queue[100];
	int timer = jobs[0]->arr_time;
	while(count < total_jobs)
	{
		// Inserting the list of available jobs(ones whose arrival time is less than the current time) in the priority queue
		while(timer >= jobs[count]->arr_time)
		{
			insert_heap(p_queue,jobs[count]);
			count++;
			if(count >= total_jobs)
				break;
		}
		// CPU stall
		if(isEmpty(p_queue))
			timer++;
		// Performing the currently available job with highest priority
		else
		{
			job_info* job = extract_root(p_queue);
			printf("t = %d Job ID = %d\n", timer, job->job_id);
			timer += job->total_burst;
			int local_tat = timer-job->arr_time;
			turn_around_time += local_tat;
			waiting_time += local_tat - job->total_burst;
		}
	}
	// When all the jobs have entered the priority queue, perform the jobs until queue is empty
	while(!isEmpty(p_queue))
	{
		job_info* job = extract_root(p_queue);
		printf("t = %d Job ID = %d\n", timer, job->job_id);
		timer += job->total_burst;
		int local_tat = timer-job->arr_time;
		turn_around_time += local_tat;
		waiting_time += local_tat-job->total_burst;
	}
	
	// Calculating the average turn around and waiting time
	float avg_tat = (float)turn_around_time / total_jobs;
	float avg_waiting_time = (float)waiting_time / total_jobs;
	
	// Printing the average turn around and waiting time
	printf("Average Turn around time = %f\n", avg_tat);
	printf("Average Waiting time = %f\n", avg_waiting_time);
}

// Function to check whether a queue is empty
int isEmptyQueue(queue* q)
{
	if(q->front == -1)
		return 1;
	return 0;
}

// Job enqueue function
void enqueue(queue* q,job_info* j)
{
	if((q->front == 0 && q->rear == QUEUE_SIZE-1) || (q->rear == (q->front-1)%(QUEUE_SIZE-1) ))
	{
		printf("Queue is full\n");
		return;
	}
	else if(q->front == -1)
	{
		q->front=q->rear=0;
		q->job_queue[q->rear]=j;
	}
	else if(q->rear == QUEUE_SIZE-1 && q->front!=0)
	{
		q->rear=0;
		q->job_queue[q->rear]=j;
	}
	else
	{
		q->rear++;
		q->job_queue[q->rear]=j;
	}
}

// Job dequeue function
void dequeue(queue* q)
{
	if(q->front == -1)
	{
		printf("Queue is empty\n");
		return;
	}
	q->job_queue[q->front]=NULL;
	if(q->front == q->rear)
	{
		q->front=q->rear=-1;
	}
	else if(q->front == QUEUE_SIZE-1)
		q->front=0;
	else
	{
		q->front++;
	}

}

// Return front element of the queue
job_info* front(queue* q)
{
	return q->job_queue[q->front];
}

//Update the front element of the queue
void update_front(queue* q,job_info* j)
{
	q->job_queue[q->front]=j;
}

void RR()
{
	printf("...........Round Robin...........\n");
	int timer = 0;
	int count = 0;
	int f;
	int turn_around_time = 0;
	int waiting_time = 0;
	int round_time = 0;
	job_info* cpu_front = NULL;
	job_info* io_front = NULL;
	queue* cpu = (queue*)malloc(sizeof(queue));
	queue* io = (queue*)malloc(sizeof(queue));
	cpu->front = cpu->rear=io->front=io->rear=-1;
	
	while((count < total_jobs) || !isEmptyQueue(cpu) || !isEmptyQueue(io))
	{
		if(count < total_jobs)
		{
			// Enqueuing the available jobs(whose arrival time is less than current time) in the CPU queue
			while(timer >= jobs[count]->arr_time)
			{
				enqueue(cpu,jobs[count]);
				count++;
				if(count >= total_jobs)
					break;
			}
		}
		
		timer++;
		
		// Flag indicating whether I/O queue was empty before CPU queue processing
		if(isEmptyQueue(io)) f = 1;
		else f = 0;
		
		// If CPU queue is not empty, proces the CPU queue
		if(!isEmptyQueue(cpu))
		{
			job_info* cpu_front = front(cpu);
			
			printf("t = %d Job ID = %d\n", timer - 1, cpu_front->job_id);
			// Decrementing the remaining time of the current CPU burst
			(cpu_front->timing[cpu_front->curr])--;
			// If the remaining time of current CPU burst reaches 0, increment the curr variable to the next I/O burst
			if(cpu_front->timing[cpu_front->curr] == 0)
			{
				cpu_front->curr++;
				// If all the CPU bursts for the process are exhausted, update the waiting and turn around time
				if(cpu_front->curr == (cpu_front->end_time_index+1))
				{
					int local_tat = timer - cpu_front->arr_time;
					turn_around_time += local_tat;
					waiting_time += local_tat - cpu_front->total_burst;
					dequeue(cpu);
				}
				//Else, set round time as 0,and enqueue the job in the I/O queue
				else
				{
					round_time = 0;
					dequeue(cpu);
					enqueue(io, cpu_front);
					
				}
			}
			else
			{
				// If round time has reached the time quantum, set round time to 0 and enqueue the job into CPU queue
				if(round_time == TIME_QUANTUM-1)
				{
					round_time = 0;
					dequeue(cpu);
					enqueue(cpu,cpu_front);
				}
				// Else, increment the round time
				else
				{
					round_time++;
					update_front(cpu, cpu_front);
				}
			}
		}
		
		// If IO queue is not empty,process the I/O queue
		if(f == 0)
		{
			job_info* io_front = front(io);
			// Decrementing the remaining time of the current I/O burst
			io_front->timing[io_front->curr]--;
			// If the remaining time of current I/O burst reches 0, increment the curr variable to next CPU burst
			if(io_front->timing[io_front->curr] == 0)
			{
				io_front->curr++;
				// If all the I/O bursts for the process are exhausted, update the waiting and turn around time
				if(io_front->curr == (io_front->end_time_index+1))
				{
					int local_tat=timer - io_front->arr_time;
					turn_around_time+=local_tat;
					waiting_time+=local_tat-io_front->total_burst;
					dequeue(io);
				}
				//Else, enqueue the job in the CPU queue
				else
				{
					dequeue(io);	
					enqueue(cpu,io_front);
				}
			}
			else
			{
				update_front(io, io_front);
			}
		}
		
		//timer++;
		
	}
	
	float avg_tat=(float)turn_around_time / total_jobs;
	float avg_waiting_time=(float)waiting_time / total_jobs;
	
	
	printf("Average Turn around time = %f\n", avg_tat);
	printf("Average Waiting time = %f\n", avg_waiting_time);
}


int main(void)
{
	input();
	sort_arrival();
	FCFS();
	printf("\n");
	priority();
	printf("\n");
	RR();
}