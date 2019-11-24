//CALCULATING NTH FIBONACCI NUMBER USING RECURSION
#include<stdio.h>
#include<time.h>

long int count;

//RECURSIVE FUNCTION TO CALCULATE NTH FIBONACCI
int fib(int n)
{	count++;
	if(n==1)
		return 0;
	if(n==2)
		return 1;
	return fib(n-1)+fib(n-2);	
	
}
int main()
{	
	clock_t start, end;
	long int f,i;
	double t;
	printf("N      Nth_term      No_of_calls      Time_taken\n");
	//LOOP TO GENERATE A TABLE DISPLAYING FIRST 47 FIBONACCI NOS, NO OF CALLS, TIME TAKEN
	for(i=1;i<=47;i++)
	{	
		count=0;
		start=clock();
		f=fib(i);
		end=clock();
		t=(double)(end-start)/CLOCKS_PER_SEC;
		printf("%2d    %15d    %15d   %15f\n",i,f,count++,t);
	}
}
