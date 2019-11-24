#include<stdio.h>
#include<string.h>

int main()
{
	char name[50];
	printf("Enter your name: ");
	scanf("%s",name);
	int a[50];
	int n,j,count=0,i=0;
	//LOOP TO PRINT THE ASCII VALUES, STORE EACH DIGIT OF ASCII CODE AS ELEMENTS OF AN ARRAY AND UPDATE THE ELEMENT COUNT
	for(j=0;j<strlen(name);j++)
	{
		n=(int)name[j];
		printf("%d",n);
		if(n>=100)
		{
			count+=3;
			a[i]=n/100;
			i++;
			a[i]=(n/10)%10;
			i++;
			a[i]=n%10;
			i++;
		}
		else
		{
			count+=2;
			a[i]=n/10;
			i++;
			a[i]=n%10;
			i++;
		}
	}
	long int int1=0,int2=0,f=1;
	//LOOP TO STORE THE FIRST HALF OF THE JUXTAPOSED NUMBER AS A LONG INT
	for(j=count/2-1;j>=0;j--)
	{
		int1=int1+a[j]*f;
		f=f*10;
		
	}
	
	f=1;
	//LOOP TO STORE THE SECOND HALF OF THE JUXTAPOSED NUMBER AS A LONG INT
	for(j=count-1;j>=count/2;j--)
	{
		int2=int2+a[j]*f;
		f=f*10;

	}
	int P[3]={1009,1013,1019};
	//LOOP TO FIND REMAINDERS OF THE SUM WHEN DIVIDED BY P
	for(j=0;j<3;j++)
	{
		printf("\nFor P= %d ,Remainder=%d",P[j],(int1+int2)%P[j]);
	}
	
}
