%{
#include<stdio.h>
#include<string.h>
int t=0;
int h=0;
int i=0;
int l=0;
char a[50],b[50],c[50],d[50];
%}

%%
[a-z] {a[t]=yytext[0]; t++;}
[0-9] {b[h]=yytext[0]; h++;}
" " {d[l]=yytext[0]; l++;}
.  {c[i]=yytext[0]; i++;}
%%

int yywrap(void) {
return 1;
}

int main(void) {
printf("Enter the string: ");
yylex();
printf("Alphabet count: %d\nNumbers count: %d\nSpecial character: %d\nWhitespace: %d\n",t,h,i,l);
printf("Alphabet: %s\nNumber: %s\nSpecial character: %s\nWhitespace: %s\n",a,b,c,d);
return 0;
}
