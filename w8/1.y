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
	if(c==0){
		printf("for loop is valid");
	}
	else{
		printf("for loop is not valid");
	}
	return 0;
}
void yyerror(char *s){
fprintf(stderr,"%s\n",s);
}
