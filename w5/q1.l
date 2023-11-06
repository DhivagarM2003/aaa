%option noyywrap
%{
#include<stdio.h>
#include<string.h>
%}
%%

[\n\t(]?([intINT]+|"i"[a-zA-Z]+|[a-zA-Z]?"nt"|"i"[a-zA-Z]?"t"|"in"[a-zA-Z]?)" " {printf("int ");}
[\n\t(]?([shortSHORT]+|s[a-zA-Z]+|[a-zA-Z]hort|s[a-zA-Z]?ort|sh[a-zA-Z]?rt|sho[a-zA-Z]?t|shor[a-zA-Z]?)" " {printf("short ");}
[\n\t(]?([floatFLOAT]+|f[a-zA-Z]?+|[a-zA-Z]?loat|f[a-zA-Z]?oat|fl[a-zA-Z]?at|flo[a-zA-Z]?t|floa[a-zA-Z]?)" " {printf("float ");}
[\n\t(]?([charCHAR]+|c[a-zA-Z]+|[a-zA-Z]?har|c[a-zA-Z]?ar|ch[a-zA-Z]?r|cha[a-zA-Z]?)" " {printf("char ");}


%%

int main(){
        yylex();
        return 0;
}

