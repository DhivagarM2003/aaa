%option noyywrap

%{
        #include<stdio.h>
%}

%%

"+" printf("||");
"-" printf("~");
"*" printf("&&");
. printf("%s",yytext);

%%

int main()
{
        yylex();
        return 0;
}

