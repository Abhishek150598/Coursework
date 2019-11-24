#include<stdio.h>
#include<stdlib.h>
# include<time.h>
int main()
{	char p[10];
	int i,num,t;
	int a[60000];
	//LOOP TO INITIALISE ALL ELEMENTS OF THE ARRAY WITH INDEX NO
	for(i=0;i<60000;i++)
	{
		a[i]=i;
	}
	srand(time(NULL));
	//LOOP TO SHUFFLE THE ELEMENTS OF THE ARRAY
	for(i=59999;i>=0;i--)
	{
		num=rand()%60000;
		t=a[num];
		a[num]=a[i];
		a[i]=t;
	}
	
	FILE *fp;
	fp=fopen("random_numbers.txt","w");
	//LOOP TO CONVERT INTEGERS TO STRING AND STORE IN FILE
	for(i=0;i<60000;i++)
	{
		itoa(a[i],p,10);
		fprintf(fp,"%s\n",p);
	}
	fclose(fp);
	
}
