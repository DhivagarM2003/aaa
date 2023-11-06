%option noyywrap
%{
#include<stdio.h>
#include<string.h>
char cond[100],b[100];
int i =0;
%}

%x block
%x if1

%%
"if"	{BEGIN if1;}
<if1>"("[^;)]*")"	{if(i!=0)
	{
		strcat(cond," && ");
		i += 4;
	}
	cond[i]='\0';
	yytext[yyleng-1] = '\0';
	strcat(cond,yytext+1);
	i += yyleng - 1;
	BEGIN block;
	}
<block>"\nif" {BEGIN if1;}
<block>"{".*"}" {strcat(b,yytext);
			printf("if(%s)\n%s\n",cond,b);
		//printf("if(%s)\n{\n",cond);
		BEGIN INITIAL;}
%%
int main()
{
	yylex();
	//printf("if(%s){\n%s\n}",cond,b);
	return 0;
}

