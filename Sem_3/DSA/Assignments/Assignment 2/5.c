/* Find whether an array is sorted or not, and the sorting order. */


#include <stdio.h>




//function to make an array with given length
void makearr(int n, int arr[n])
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("Enter the element of array[%d] = ",i+1);
		scanf("%d",&arr[i]);
	}
}



//function to print the array
void printarr(int n, int arr[n])
{
	int i;
	printf("\n\n\nThe array obtained is: \n");
	for(i=0; i<n; i++)
	{
		printf("%d ",arr[i]);
	}
	printf("\n\n\n");
}



//function to check the array elements are equal or not
int equal(int n, int arr[n])
{
	int i;
	int flag=0;
	for(i=1; i<n; i++)
	{
		if(arr[i] != arr[i-1])
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
		return 1;
	return 0;
}



//function to check the array elements are in ascending order
int ascending(int n, int arr[n])
{
	int i;
	int flag=0;
	for(i=1; i<n; i++)
	{
		if(arr[i]<arr[i-1])
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
		return 1;
	return 0;
}



//function to check the array elements are in descending order
int descending(int n, int arr[n])
{
	int i;
	int flag=0;
	for(i=1; i<n; i++)
	{
		if(arr[i]>arr[i-1])
		{
			flag = 1;
			break;
		}
	}
	if(flag==0)
		return 1;
	return 0;
}				



//main function
int main()
{
	int n;
	printf("Enter the number of elements of the array: ");
	scanf("%d", &n);
	int arr[n];
	makearr(n, arr);
	printarr(n, arr);
	if(equal(n, arr) == 1)
		printf("The elements of the array are equal to each other.\n\n");
	else
	{
		if(ascending(n, arr)==1)
			printf("The elements are sorted and in ascending order.\n\n");
		else
		{
			if(descending(n,arr)==1)
				printf("The elements are sorted and in descending order.\n\n");
			else
				printf("The elements are not sorted.\n\n");
		}
	}


	return 0;
}

