%{
#include<stdio.h>
int l;
%}

%%
"+"[0-9][0-9][0-9]?(-|" ")[0-9]+ {printf("Valid number\n");}
.* {printf("Not valid number\n");}
%%

int yywrap(){
return 1;
}

int main(){
printf("Enter phone no: ");
yylex();
return 0;
}
