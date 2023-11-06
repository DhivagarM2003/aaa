%{
#include "y.tab.h"
#include <stdio.h>
extern int yylval;
void yyerror(char *s);
int yylex();
int c=0,max=0;
 
%}
%token NUMBER;
%token BRACKET;
%%
program:
       program expr {}
|
;
expr: NUMBER {$$=++c; if(c>max) max++;}
    | BRACKET {$$=--c;}
    ;
%%
int main(){
	yyparse();
	printf("%d",max);
	return 0;
}
void yyerror(char *s){
fprintf(stderr,"%s\n",s);
}

