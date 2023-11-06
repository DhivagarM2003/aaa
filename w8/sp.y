%{
#include "y.tab.h"
#include <stdio.h>
extern int yylval;
void yyerror(char *s);
int yylex();
int d=0,c=0,e=0,f=0;
%}

%token NUM;
%token OP;
%%
program:
       program expr {}
|
;
expr: NUM {$$=++c;}
    | OP {$$=++d;if(c==0)f=1;}
    ;
%%
int main(){
yyparse();
if(c==d+1 && f==1){
printf("Valid");
}
else{
printf("Invalid");
}
return 0;
}
void yyerror(char *s){
printf(stderr,"%s\n",s);
}

