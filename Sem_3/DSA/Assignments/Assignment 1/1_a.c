//FACTOIAL USING ITERATION
#include<stdio.h>

int main()
{	
	int n,i;
	long int fact=1;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	//CHECKING FOR N=0
	if(n==0)
	{
		printf("The required factorial is 1");
		return 0;
	}
	//LOOP TO FIND FACTORIAL OF N
	for(i=1;i<=n;i++)
	{
		fact=fact*i;
	}
	printf("The required factorial is: %d",fact);
}
