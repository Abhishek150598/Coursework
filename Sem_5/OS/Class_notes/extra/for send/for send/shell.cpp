#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "iostream"

using namespace std;

inline int strlen(char* arr)
{
    int len=0;
    while(arr[len]!='\0')
        len++;
    return len;
}
inline int strcmp(char* str1,char* str2)
{
    if(strlen(str1)!=strlen(str2))
        return 0;
    int len=strlen(str1);
    while(len>0)
    {
        len--;
        if(str1[len]!=str2[len])
            return 0;
    }
    return 1;
}

char* append(char* str1,char* str2)
{
	int len1=strlen(str1);
	int len2=strlen(str2);
	char* str=(char*)malloc(sizeof(char)*(len1+len2+1));
	int x=0;
	//char str[100];
	while(x<=len1)
    {
		str[x]=str1[x];
		x++;
	}
	x--;
	while(x<=len1+len2)
	{
		str[x]=str2[x-len1];
		x++;
	}
	str[x]='\0';
	return str;

}
int main(int argv,char** argc)
{
	//printf("%s",append("okay","good"));
	char* path="/home/arnab22/Desktop/labs/bash_assignments/test/";
	char str[100];
	printf("Welcome to ASH\n");
	int x=0;
	char* command;
	printf("%s$> ",path);
	cin>>str;
	command=append(path,str);
	pid_t pid=fork();
	while(true)
    {
		if(pid==0)
		{
			system(command);
			//sleep(1);
		}
        else if(pid>=0)
        {
			sleep(1);
			printf("%s$>",path);
			cin>>str;
			if(strcmp("exit",str))
				break;
			command=append(path,str);
			pid=fork();
		}
		else
        {
			printf("\nFork failed\n");
			exit(EXIT_FAILURE);
		}
	}
	return 0;
}
