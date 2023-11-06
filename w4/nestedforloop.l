%option noyywrap
%{
	#include<string.h>
	#include<stdio.h>
	char incr[100]="",temp[100]="",brace[]="\n}\n";
%}

for     "for"

%x loop1
%x loop2
%x loop3
%x stmt

%%

"for" {
	BEGIN loop1;
}
<loop1>"("[^;)]*";" {
	printf("%s\n",(yytext+1)); 
	unput(';');
        BEGIN loop2;
}
<loop2>";"[^;)]*";" {
	yytext[yyleng-1]='\0';
        printf("while(%s)",(yytext+1)); 
	unput(';');
        BEGIN loop3;
}
<loop3>";"[^;)]*")" {
	yytext[yyleng-1]=';';
	strcpy(temp,yytext+1);
	strcat(temp,brace);
	strcat(temp,incr);
	strcpy(incr,temp); 
	BEGIN stmt;
}
<stmt>"for"     {
	BEGIN loop1;
}
<stmt>[^{}{for}]* {
	printf("%s",yytext);
}
<stmt>"}" {
	printf("%s\n",incr);
	BEGIN INITIAL;
}
.
%%

int main(){
	yyin = fopen("for.txt","r");
	yylex();
	return 0;
}
