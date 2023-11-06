%{
#include<stdio.h>
#include<stdlib.h>
#include"y.tab.h"
int yywrap(void);
%}
 
%%
[0-9]+ {yylval=atoi(yytext);
return STR;}
[a-z]+["="][0-9]+[";"] {yylval = strdup(yytext);
return INIT;
}
"while" {yylval = strdup(yytext);
return WHILE;
}
[a-z]+[<>=]+[0-9]+ {yylval = strdup(yytext);
return COND;
}
"{" return OPEN;
"}" return CLOSE;
"(" return SO;
")" return SC;
[+-/*\n] return *yytext;
[ \t] {}
. {printf("invalid string");}
%%
 
int yywrap(void)
{
return 1;
}

