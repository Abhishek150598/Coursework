#include<stdio.h>
#include<string.h>

//FUNCTION FOR SORTING THE NAMES AND STORING IN FILE
void bubble_sort(int i,char c[][30])
{	
	int j,k;
	char t[30];
	for (j=0;j<=i-1;j++)
	{
		for(k=0;k<=i-1-j;k++)
		{
			if(strcmp(c[k],c[k+1])>0)
			{
				strcpy(t,c[k]);
				strcpy(c[k],c[k+1]);
				strcpy(c[k+1],t);			
			}
		}
	}
	FILE *fp2;
	fp2=fopen("sorted_output.txt","w");
	
	for(j=0;j<=i;j++)
	{
		fprintf(fp2,"%s\n",c[j]);
		
	}
	fclose(fp2);
}


int main()
{	
	char c[30][30];
	FILE *fp;
	fp=fopen("namelist.txt","r");
	int max_len,min_len,max_pos,min_pos,l,i=0;
	fscanf(fp,"%s",c[i]);
	//INITIALISING THE LARGEST AND SHORTEST NAME AS THE FIRST NAME
	max_len=strlen(c[i]);
	min_len=strlen(c[i]);
	max_pos=i;
	min_pos=i;
	//LOOP TO INPUT NAMES AND UPDATE LARGEST AND SHORTEST NAMES
	while(!feof(fp))
	{
		i++;
		fscanf(fp,"%s",c[i]);
		l=strlen(c[i]);
		if(l>max_len)
		{
			max_len=l;
			max_pos=i;
		}
		else if(l<min_len)
		{	
			min_len=l;
			min_pos=i;
		}
	}
	
	printf("The largest string is %s with %d characters.\n",c[max_pos],max_len);
	printf("The shortest string is %s with %d characters.\n",c[min_pos],min_len);
	
	bubble_sort(i,c);
	fclose(fp);
	
}
