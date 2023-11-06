%{
#include <stdio.h>
#include <stdlib.h>
%}

%union {
    char *str;
}

%token <str> INT FLOAT IDENTIFIER LBRACE RBRACE SEMICOLON COMMA STRUCT 
%type <str> data_type

%start structure

%%

structure:
    data_type IDENTIFIER LBRACE members RBRACE SEMICOLON
    {
        printf("Structure validated successfully!\n");
    }
;

data_type:
    INT             { $$ = $1; }
    | FLOAT         { $$ = $1; }
    | STRUCT	    { $$ = $1; }
;

members:
    member
    | members member
;

member:
    data_type IDENTIFIER SEMICOLON
    {
        printf("Member: %s %s\n", $1, $2);
        free($1); // free the memory allocated by strdup in Lex
        free($2); // free the memory allocated by strdup in Lex
    }
;

%%

int main() {
    yyparse();
    return 0;
}

void yyerror(const char *s) {
    fprintf(stderr, "Error: %s\n", s);
}

