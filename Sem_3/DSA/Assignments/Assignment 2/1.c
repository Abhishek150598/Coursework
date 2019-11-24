#include <stdio.h>
//#include <math.h>
#include <stdlib.h>



//function to make polynomials
void makepoly(int* a, int n)
{
	int i;
	for(i=0; i<n; i++)
	{
		scanf("%d", &a[i]);
	}
}



//function to get maximum between two numbers
int maximum(int a, int b)
{
	return (a>b)?a:b;
}



//function to determine the degree of the polynomial
void degree(int* a, int n)
{
	int i = 0;
	while(i<n)
	{
		if(a[i] == 0)
			i++;
		else
			break;
	}
	if(i >= n-1)
		printf("\nThe polynomial is of zeroth order.\n");
	else
		printf("\nThe polynomial is of order %d.\n", n-i-1);
	
}



//function to add two polynomials
void addition(int* a, int* b, int n, int m)
{
	int i;
	int max = maximum(n, m);
	int* sum;
	sum = (int*)malloc(max*sizeof(int));
	
	for(i=0; i<n; i++)
	{
		sum[i] = a[i];
	}
	for(i=0; i<m; i++)
	{
		sum[i] = sum[i] + b[i];
	}
	
	for(i=0; i<max; i++)
	{
		a[i] = sum[i];
		if(sum[i] != 0)
		{
			//to print the coefficients
			printf("%d", sum[i]);
			//to print the power to the variables
			if(i != 0)
				printf("x^%d", i);
			//to print the '+' or '-' signs in between
			if(sum[i] > 0)
			{	
				if(i != max-1)
					printf("+");
			}
			else
			{
				sum[i] = sum[i]*(-1);
				if(i != max-1)
					printf("-");
			}
		}
	}
	degree(sum, max);
	printf("\n\n");
}



//function to subtract one polynomial from another
void subtraction(int* a, int* b, int n, int m)
{
	int i;
	int max = maximum(n, m);
	int* sum;
	sum = (int*)malloc(max*sizeof(int));
	
	for(i=0; i<n; i++)
	{
		sum[i] = a[i];
	}
	for(i=0; i<m; i++)
	{
		sum[i] = sum[i] - b[i];
	}
	
	for(i=0; i<max; i++)
	{
		a[i] = sum[i];
		if(sum[i] != 0)
		{
			//to print the coefficients
			printf("%d", sum[i]);
			//to print the power to the variables
			if(i != 0)
				printf("x^%d", i);
			//to print the '+' or '-' signs in between
			if(sum[i] > 0)
			{	
				if(i != max-1)
					printf("+");
			}
			else
			{
				sum[i] = sum[i]*(-1);
				if(i != max-1)
					printf("-");
			}
		}
	}
	degree(sum, max);
	printf("\n\n");
}



//function to multiply two polynomials
void multiplication(int* a, int* b, int n, int m)
{
	int i,j;
	int max = m+n-1;
	int* mul;
	mul = (int*)malloc(max*sizeof(int));
	for(i=0; i<n; i++)
	{
		for(j=0; j<m; j++)
		{
			mul[i+j] = a[i]*b[j];
		}
	}
	
	for(i=0; i<max; i++)
	{
		a[i] = mul[i];
		if(mul[i] != 0)
		{
			//to print the coefficients
			printf("%d", mul[i]);
			//to print the power to the variables
			if(i != 0)
				printf("x^%d", i);
			//to print the '+' or '-' signs in between
			if(mul[i] > 0)
			{	
				if(i != max-1)
					printf("+");
			}
			else
			{
				mul[i] = mul[i]*(-1);
				if(i != max-1)
					printf("-");
			}
		}
	}
	printf("\n\n");
}



//function to multiply a polynomial with a constant
void constant(int* a, int n)
{
	int term;
	printf("Enter the constant term to be multiplied with the polynomial: ");
	scanf("%d", &term);
	int i;
	int* mul;
	mul = (int*)malloc(n*sizeof(int));
	for(i=0; i<n; i++)
	{
		mul[i] = a[i]*term;
	}
	for(i=0; i<n; i++)
	{
		//a[i] = mul[i];
		//to print the coefficients of the final polynomial
		printf("%d", mul[i]);
		//to print te power to the variables
		if(i != 0)
			printf("x^%d", i);
		//to print 
		if(i != n-1)
			printf("+");
	}
	printf("\n\n");
}



//main function
int main()
{
	int n, m, choice;
	printf("Enter the size of the first polynomial: ");
	scanf("%d", &n);
	printf("Enter the size of the second polynomial: ");
	scanf("%d", &m);
	int* a;
	int* b;
	a = (int*)malloc(n*sizeof(int));
	b = (int*)malloc(m*sizeof(int));
	printf("Enter the first polynomial: ");
	makepoly(a, n);
	printf("\nEnter the second polynomial: ");
	makepoly(b, m);
	do
	{
		printf("\n\nChoose one of the following options:\n1.Add two polynomials\n2.Subtract one polynomial from another polynomial\n3.Multiply two polynomials\n4.Multiply the first polynomial with constant\n5.Multiply the second polynomial with constant\n6.Degree of the polynomial\n");
		scanf("%d", &choice);
		if(choice == 1)
			addition(a, b, n, m);
		else if(choice == 2)
			subtraction(a, b, n, m);
		else if(choice == 3)
			multiplication(a, b, n, m);
		else if(choice == 4)
			constant(a, n);
		else if(choice == 5)
			constant(b, m);
		else if(choice == 6)
		{
			int sub;
			printf("Choose one: \n1.Degree of the first polynomial\n2.Degree of the second polynomial\n");
			scanf("%d", &sub);
			if(sub == 1)
				degree(a, n);
			else if(sub == 2)
				degree(b, m);
			else
				printf("Choose between 1 or 2\n");
		}
		else
			printf("Choose an option from the list\n");
	}
	while(choice>0 && choice<=6);
	
	
	return 0;
}
	
	
	
	
	
	
	
	
	




