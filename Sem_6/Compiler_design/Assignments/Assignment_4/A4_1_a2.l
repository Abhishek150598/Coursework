%{ 
   /* Definition section */
  	#include "y.tab.h" 
%} 
  
/* Rule Section */
%% 
\n { printf("valid string\n"); return 0;}
^[aA]*[bB]*$ { printf("valid string\n"); return 0;}
^.*$ { printf("invalid string\n"); return 0;}
%% 
  
int yywrap()  
{  
	return 1;  
}  

int main()
{
	printf("Enter the string: \n");
	yylex();
}
