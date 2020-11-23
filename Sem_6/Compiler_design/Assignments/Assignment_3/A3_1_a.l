%{
int charcount = 0, linecount = 0, wordcount = 0;
%}

%%
[ ] {wordcount++;}
. charcount++;
\n {linecount++; charcount++; wordcount++;}
%%

int main()
{
	yyin = fopen("input.txt","r");
	yylex();
	printf("Characters: %d\nWords: %d\nLines: %d\n",charcount, wordcount, linecount);
	return 0;
}
