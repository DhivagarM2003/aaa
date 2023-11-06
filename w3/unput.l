%option noyywrap
%{
#include<stdio.h>
#include<string.h>
#undef YY_BUF_SIZE
#define YY_BUF_SIZE 1024*1024
%}

%%
"("[0-9]+")" {printf("%s",yytext);}
[0-9]+ { char *yycopy = strdup(yytext); unput(')');
for(int i=yyleng-1;i>=0;i--)
unput(yycopy[i]);
unput('(');
free(yycopy);
}
\n {return 0;}


%%

int main()
{
yylex();
return 0;
}
