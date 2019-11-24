//LINEAR AND BINARY SEARCH(FLOAT)
#include<stdio.h>

//FUNCTION FOR LINEAR SEARCH
int linear_search(float *a,int n,float se)
{	int i;
	for(i=0;i<n;i++)
	{
		if(a[i]==se)
			return i;
	}

	return -1;
}
//FUNCTION FOR BINARY SEARCH
int binary_search(float *a,int n,float se)
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
	int n, i, pos1,pos2;
	float se, a[50];
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{	
		scanf("%f",&a[i]);
	}
	printf("Enter the SEARCH element: \n");
	scanf("%f",&se);
	//FUNCTION CALL FOR LINEAR SEARCH
	printf("USING LINEAR SEARCH\n");
	pos1=linear_search(a,n,se);
	if(pos1==-1)
		printf("ELEMENT NOT FOUND:(\n");
	else
		printf("ELEMENT FOUND AT POSITION %d\n",pos1);
	
	//FUNCTION CALL FOR BINARY SEARCH
	printf("USING BINARY SEARCH\n");	
	pos2=binary_search(a,n,se);
	if(pos2==-1)
		printf("ELEMENT NOT FOUND:(\n");
	else
		printf("ELEMENT FOUND AT POSITION %d\n",pos2);
}
	
