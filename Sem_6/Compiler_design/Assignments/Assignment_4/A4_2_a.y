%{ 
   /* Definition section */
   #include<stdio.h> 
   #include<stdlib.h> 
%} 
  
%token INT NL 
%left ADDOP
  
/* Rule Section */
%% 
stmt: EXP NL  { printf("Result is: %d\n", $$); 
              exit(0); } 
; 
EXP:EXP ADDOP EXP {$$=$1+$3;} | INT  {$$ = $1;}
; 
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
