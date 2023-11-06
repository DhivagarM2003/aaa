%option noyywrap
%{
#include<stdio.h>
#include<string.h>
char c[5][10];
int i=0;
%}

%%

"<"		 {int j,k=0;
		char ch[10],in;
		if((in = input()) != '/')
		{
                        ch[k]=in;
                        k++;
                }

		while((in = input()) != '>')
		{
			ch[k]=in;
			k++;
		}
		ch[k]='\0';
		for(j=0;j<i;j++)
			if(strcmp(ch,c[j]) == 0)
				break;
		if(j>=i)
		{
			printf("\n %s ",ch);
			strcpy(c[i],ch);
			i++;
		}
		}
"\n"|" "	{}


%%
int main()
{
	FILE *fp=fopen("sp1.html","r");
	if(fp)
		yyin=fp;
	yylex();
	return 0;
}

