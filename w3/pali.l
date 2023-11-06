%{
#include<stdio.h>
%}
%%
([0-9a-zA-Z])* {int i;
	for(i=0;i<yyleng/2;i++)
	{
	if(yytext[i]!=yytext[yyleng-1-i])
	{
		printf("Not palindrome\n");
		break;
	}
	}
if(i>=yyleng/2)
	printf("Palindrome\n");}
%%
int yywrap(){
return 1;}
int main(){
	yylex();
	return 0;
}
