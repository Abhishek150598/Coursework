%{
#include <stdio.h>
#include <string.h>
char integers[100][100]; int ctr1 = 0;
char floats[100][100]; int ctr2 = 0;
%}

INTEGERS [+-]?[0-9]+
FLOAT [+-]?[0-9]+\.[0-9]+

%%
{INTEGERS} {strcpy(integers[ctr1], yytext); ctr1++;}
{FLOAT} {strcpy(floats[ctr2], yytext); ctr2++;}
.|\n {}
%%

int main(int argc, char *argv[])
{
	yyin = fopen("input.txt","r");
	yylex();
	printf("Integers are:\n");
	for(int i = 0; i < ctr1; i++)
	{
		printf("%s\n", integers[i]);
	}
	printf("\nFloating point numbers are:\n");
	for(int i = 0; i < ctr2; i++)
	{
		printf("%s\n", floats[i]);;
	}
}

int yywrap()
{
	return 1;
}