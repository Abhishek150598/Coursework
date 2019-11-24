//FACTORIAL USING RECURSION
#include<stdio.h>

//RECURSIVE FUNCTION TO CALCULATE FACTORIAL
long int fact(int n)
{
	if(n==0)
		return 1;
	if(n==1)
	 	return 1;
	return n*fact(n-1);
	
}

int main()
{	
	int n;
	long int f;
	printf("Enter the value of n: ");
	scanf("%d",&n);
	f=fact(n);
	printf("The required factorial is: %d",f);
}
