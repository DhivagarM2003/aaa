%option noyywrap

%{
        #include<stdio.h>
        char s[100];
        int c=0;
%}

%%

"{"|"("|"[" {printf("%c",yytext[0]);s[c++]=yytext[0];}
"}" {printf("%c",yytext[0]); if(s[c-1]=='{') c--;}
")" {printf("%c",yytext[0]); if(s[c-1]=='(') c--;}
"]" {printf("%c",yytext[0]); if(s[c-1]=='[') c--;}

%%

int main()
{
        yyin = fopen("sample.c","r");
        yylex();
        if(c==0)
                printf("Balanced parenthesis");
        else
                printf("Unbalanced parenthesis");
        return 0;
}

