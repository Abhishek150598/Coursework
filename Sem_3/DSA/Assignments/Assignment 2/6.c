/* Given two sorted arrays , write a function to merge the array in the sorting order. */


#include <stdio.h>


//function to make an array with given length
void makearr(int n, int arr[n])
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("The element %d of the array = ",i+1);
		scanf("%d",&arr[i]);
	}
}


//function to print array
void printarr(int n, int arr[n])
{
	int i;
	for(i=0; i<n; i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
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

//function to check the sorting order of the input arrays
int check(int m, int arr[m])
{
	int res;	
	if(equal(m, arr)==1)
		res=0;
	else
	{
		if(ascending(m, arr)==1)
			res=1;
		else
		{
			if(descending(m, arr)==1)
				res=2;
			else
				res=3;
		}
	}
	return res;
}


//fucntion to check if both the arrays have same sorting order
int same_sort(int m, int n, int arr1[m], int arr2[n])
{
	int res1 = check(m, arr1);
	int res2 = check(n, arr2);
	int result;
	if(res1==3 || res2==3)
	{
		printf("One or both of the arrays are not sorted. So, we cannot merge.\n\n");
		result = 3;
	}
	else
	{
		if(res1==res2)
		 	result = res1;
		else
		{
			printf("The arrays are not sorted in the same order.So, we cannot merge them.\n\n");
			result = 3;
		}
	}
	return result;
}


//function to create a big array
void bigarr(int m, int n, int r, int arr1[m], int arr2[n], int arr[r])
{
	int i,j;
	int res = same_sort(m, n, arr1, arr2);
	if(res==1)
	{
		if(arr1[0]<arr2[0])
		{
			for(i=0; i<m; i++)
			{
				for(j=0; j<n j++)
				{
					while(arr1[j]<arr2[i])
						
		}
			
	}
	if(res==0)
	{
		if(arr1[0]==arr2[0])
		{
			for(i=0; i<m; i++)
				arr[i] = arr1[i];
			for(i=m; i<r; i++)
				arr[i] = arr2[i-m];
			printarr(r, arr);
			
		}
		else
			printf("\nThe arrays cannot be merged as they are equal individually but not equal to each other.\n");
	}
	
}





//main function
int main()
{
	int m,n;
	
	printf("Enter the lengths of two arrays: \n");
	scanf("%d %d",&m,&n);
	
	int arr1[m];
	int arr2[n];
	int r = m+n;
	int arr[r];

	printf("Enter the elements of the first array: \n");
	makearr(m, arr1);
	printf("\nEnter the elements of the second array: \n");
	makearr(n, arr2);

	printf("\nThe first array is: ");
	printarr(m, arr1);

	printf("\nThe second array is: ");
	printarr(n, arr2);

	bigarr(m, n, r, arr1, arr2, arr);

	
	return 0;
}




