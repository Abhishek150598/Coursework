//LINEAR AND BINARY SEARCH(WORDS)
#include<stdio.h>
#include<string.h>
//FUNCTION FOR LINEAR SEARCH
int linear_search(char a[][50],int n,char *se)
{	int i;
	for(i=0;i<n;i++)
	{
		if(strcmp(a[i],se)==0)
			return i;
	}

	return -1;
}
//FUNCTION FOR BINARY SEARCH
int binary_search(char a[][50],int n,char *se)
{	
	int beg,end,mid;
	beg=0;
	end=n-1;
	mid=(beg+end)/2;
		
	while(beg<=end)
	{
		if(strcmp(se,a[mid])==0)
			return mid;		
		else if(strcmp(se,a[mid])<0)
			end=mid;
		else
			beg=mid;
		
		mid=(beg+end)/2;
	}

	return -1;
}

//FUNCTION FOR BUBBLE SORT
void bubble_sort(char a[][50],int n)
{	char t[50];
	int i,j;
	for(i=0;i<=n-2;i++)
	{
		for(j=0;j<=n-2-i;j++)
		{
			if(strcmp(a[j],a[j+1])>0)
			{
				strcpy(t,a[j]);
				strcpy(a[j],a[j+1]);
				strcpy(a[j+1],t);			
			}
		}
	}
}
int main()
{
	int n, i, pos1,pos2;
	char se[50], a[50][50];
	printf("Enter the number of elements: \n");
	scanf("%d",&n);
	printf("Enter the elements: \n");
	for(i=0;i<n;i++)
	{	
		scanf("%s",a[i]);
	}
	printf("Enter the SEARCH element: \n");
	scanf("%s",se);
	//FUNCTION CALL FOR LINEAR SEARCH
	printf("USING LINEAR SEARCH\n");
	pos1=linear_search(a,n,se);
	if(pos1==-1)
		printf("ELEMENT NOT FOUND:(\n");
	else
		printf("ELEMENT FOUND AT POSITION %d\n",pos1);
	bubble_sort(a,n);
	//FUNCTION CALL FOR BINARY SEARCH
	printf("USING BINARY SEARCH\n");	
	pos2=binary_search(a,n,se);
	if(pos2==-1)
		printf("ELEMENT NOT FOUND:(\n");
	else
		printf("ELEMENT FOUND AT POSITION %d\n",pos2);
}
	
