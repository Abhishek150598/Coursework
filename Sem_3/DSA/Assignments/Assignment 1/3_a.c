//LINEAR AND BINARY SEARCH(INTEGERS)
#include<stdio.h>

//FUNCTION FOR LINEAR SEARCH
int linear_search(int *a,int n,int se)
{	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==se)
			return i;
	}

	return -1;
}

//FUNCTION FOR BINARY SEARCH
int binary_search(int *a,int n,int se)
{	
	int beg,end,mid;
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
		
	while(beg<=end)
	{
		if(se==a[mid])
			return mid;		
		else if(se<a[mid])
			end=mid;
		else
			beg=mid;
		
		mid=(beg+end)/2;
	}

	return -1;
}

int main()
{
	int n, se, a[50], i, pos1,pos2;
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{	
		scanf("%d",&a[i]);
	}
	printf("Enter the SEARCH element: \n");
	scanf("%d",&se);
	
	printf("USING LINEAR SEARCH\n");
	pos1=linear_search(a,n,se);
	if(pos1==-1)
		printf("ELEMENT NOT FOUND:(\n");
	else
		printf("ELEMENT FOUND AT POSITION %d\n",pos1);
	
	printf("USING BINARY SEARCH\n");	
	pos2=binary_search(a,n,se);
	if(pos2==-1)
		printf("ELEMENT NOT FOUND:(\n");
	else
		printf("ELEMENT FOUND AT POSITION %d\n",pos2);
}
	
