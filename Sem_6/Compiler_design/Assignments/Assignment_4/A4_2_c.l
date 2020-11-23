%{ 
   /* Definition section */
  #include "y.tab.h"
  extern yylval; 
%} 
  
/* Rule Section */
%% 
[0-9]+ {yylval = atoi(yytext); return INT;} 
"+" {return ADDOP;}
"*" {return MULOP;}
"%" {return MODOP;}
"^" {return EXPOP;}
\n {return NL;} 
.  {return yytext[0];} 
%% 
  
int yywrap()  
{  
	return 1;  
}  