%{
#include <stdio.h>
%}

SL_COMMENT "//".*\n
ML_COMMENT "/*"(.|\n)*"*/"
KEYWORD "else"|"if"|"for"|"int"|"float"|"void"|"return"
ARITHOP "+"|"-"
RELOP ">"|"<"
ASSIGNOP "="
PUNCTUATION ";"|","|"("|")"|"{"|"}"
INUM [0-9]+
NUM [0-9]+\.[0-9]+
ID [A-Za-z_][A-Za-z0-9_]*
INVALID [0-9][A-Za-z0-9_]*

%%
{SL_COMMENT} {}
{ML_COMMENT} {}
{KEYWORD} {printf("%s\tkeyword\n", yytext);}
{ARITHOP} {printf("%s\tarith-op\n", yytext);}
{RELOP} {printf("%s\trel-op\n", yytext);}
{ASSIGNOP} {printf("%s\tassign-op\n", yytext);}
{PUNCTUATION} {printf("%s\tpunctuation\n", yytext);}
{INUM} {printf("%s\tinum\n", yytext);}
{NUM} {printf("%s\tnum\n", yytext);}
{ID} {printf("%s\tid\n", yytext);}
{INVALID} {printf("%s\tinvalid\n", yytext);}
.|\n {}
%%

int main(int argc, char *argv[])
{
	yyin = fopen("input.txt","r");
	yylex();
}

int yywrap()
{
	return 1;
}