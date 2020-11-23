%{ 
   /* Definition section */
   #include<stdio.h> 
   #include<stdlib.h> 
%} 
  
%token FLOAT NL
%left ADDOP
%left MULOP
%left EXPOP 
  
/* Rule Section */ 
%% 
stmt: EXP NL  { printf("Result is %f\n", $$); 
              exit(0); } 
; 
EXP: EXP ADDOP EXP {$$ = $1 + $2;} | EXP MULOP EXP {$$ = $1 * $2;} | EXP EXPOP EXP {$$ = pow($1 ,$3);} | FLOAT {$$ = $1;}

%% 
  
int yyerror(char *msg) 
 { 
  printf("invalid string\n"); 
  exit(0); 
 } 
  
main() 
 { 
  printf("enter the string\n"); 
  yyparse(); 
 } 
