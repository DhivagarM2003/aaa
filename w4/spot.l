%option noyywrap
%{
#include<stdlib.h>
#include<stdio.h>
        int stack[100];
        void pop();
        void push(int);
        int priority(int);
        int top();
        int tos=0;
%}

%%
[0-9]? { int a = atoi(yytext); push(a);}
"+"     {int a = top();pop();
         int b = top();pop();
         int c = a+b; push(c);
        }
"-"     {int a = top();pop();
         int b = top();pop();
         int c = a-b; push(c);
        }
"*"     {int a = top();pop();
         int b = top();pop();
         int c = a*b; push(c);
        }
"/"     {int a = top();pop();
         int b = top();pop();
         int c = a/b; push(c);
        }

%%

int main()
{
        yylex();
        int a = top();
        printf("%d",a);
        return 0;

}
void pop()
{
        tos--;
}
int top()
{
        return stack[tos-1];
}
void push(int c){
        stack[tos]=c;
        tos++;
}
