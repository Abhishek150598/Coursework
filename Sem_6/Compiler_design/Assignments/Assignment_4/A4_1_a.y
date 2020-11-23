%{ 
   /* Definition section */
   #include<stdio.h> 
   #include<stdlib.h> 
%} 
  
%token A B NL 
  
/* Rule Section */
%% 
stmt: S NL  { printf("valid string\n"); 
              exit(0); } ; 
S: P Q | 
; 
P: A P | 
;
Q: B Q | 
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
