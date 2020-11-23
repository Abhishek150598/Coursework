%{ 
   /* Definition section */
  #include "y.tab.h" 
  extern yylval;
%} 
  
/* Rule Section */
%% 

[+-]?[0-9]*\.*[0-9]* {yylval = atof(yytext); return FLOAT;} 
"+" {return ADDOP;}
"*" {return MULOP;}
"^" {return EXPOP;}
\n {return NL;} 
.  {return yytext[0];} 
%% 
  
int yywrap()  
{  
	return 1;  
}  