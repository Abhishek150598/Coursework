%{
#include <stdio.h>
#include <string.h>
char acronyms[100][100]; int ctr1 = 0;
char propernames[100][100]; int ctr2 = 0;
%}

CHARACTERS [A-Za-z0-9]
UPPERCASE [A-Z]
PROPERNAME {UPPERCASE}{CHARACTERS}*
ACRONYM {UPPERCASE}+

%%
{ACRONYM} {strcpy(acronyms[ctr1], yytext); ctr1++;}
{PROPERNAME} {strcpy(propernames[ctr2], yytext); ctr2++;}
.|\n {}
%%

int main(int argc, char *argv[])
{
	yyin = fopen("input.txt","r");
	yylex();
	printf("Acronyms are:\n");
	for(int i = 0; i < ctr1; i++)
	{
		printf("%s\n", acronyms[i]);
	}
	printf("\nProper names are:\n");
	for(int i = 0; i < ctr2; i++)
	{
		printf("%s\n", propernames[i]);;
	}
}

int yywrap()
{
	return 1;
}