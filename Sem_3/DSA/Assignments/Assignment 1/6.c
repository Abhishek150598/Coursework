#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{	//ARRAY P INITIALISED WITH 3 FOUR-DIGIT PRIME NOS
	int P[3]={1009,1013,1019};
	long int i,j, a[10];
	int r[10];
	srand(time(NULL));
	//LOOP TO GENERATE LARGE INTEGERS Li AND THEIR REMAINDERS Ri WHEN DIVIDED BY P
	for(j=0;j<3;j++)
	{
		printf("P= %d\n",P[j]);
		for(i=0;i<10;i++)
		{
			a[i]=rand()+10000;
			r[i]=a[i]%P[j];
			printf("%ld %d\n",a[i],r[i]);
		}
		printf("\n");
	}
}
