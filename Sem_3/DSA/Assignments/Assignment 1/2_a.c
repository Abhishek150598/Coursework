//CALCULATING NTH FIBONACCI NUMBER USING ITERATION 
#include<stdio.h>

int main()
{	
	int n,i;
	long int first_term, second_term, third_term;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	//PRINTING THE RESULT FOR N=1
	if(n==1)
	{
		printf("The required term is 0");
		return 0;
	}
	//PRINTING THE RESULT FOR N=2
	if(n==2)
	{
		printf("The required term is 1");
		return 0;
	}
	//INITIALISING FIRST AND SECOND TERMS AS 0 AND 1 RESPECTIVELY
	first_term=0;
	second_term=1;
	//LOOP TO CALCULATE RESULT FOR N>2
	for(i=3;i<=n;i++)
	{
		third_term=first_term+second_term;
		first_term=second_term;
		second_term=third_term;
		
	}
	printf("The required term is %d",&third_term);
	return 0;
}
