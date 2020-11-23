%{ 
   /* Definition section */
   #include<stdio.h> 
   #include<stdlib.h> 
%} 
  
%token INT NL 
%left ADDOP
%left MULOP
%left MODOP
%left EXPOP
  
/* Rule Section */ 
%% 
stmt: EXP NL  { printf("Result is %d\n", $$); 
              exit(0); } 
; 
EXP: EXP ADDOP EXP {$$ = $1 + $3;} | EXP MULOP EXP {$$ = $1 * $3;} | EXP MODOP EXP {$$ = $1 % $3;} | EXP EXPOP EXP {$$ = (int)pow($1 ,$3);} | INT {$$ = $1;}
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
