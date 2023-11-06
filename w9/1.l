%{
#include "y.tab.h"
#include <string.h>
#include <stdlib.h>
%}

%%

[ \t\n] ;
"int" { yylval.str = strdup("int"); return INT; }
"float" { yylval.str = strdup("float"); return FLOAT; }
"struct" {yylval.str = strdup("struct"); return STRUCT; }
"{" return LBRACE;
"}" return RBRACE;
";" return SEMICOLON;
"," return COMMA;
[a-zA-Z_][a-zA-Z_0-9]* { yylval.str = strdup(yytext); return IDENTIFIER; }
. return *yytext;

%%

int yywrap() {
    return 1;
}

