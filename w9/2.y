%{
 
#include<stdio.h>
#include<stdlib.h>
int yylex(void);
void yyerror(char *s);
int i=0;
char p='p';
int l=0;
char init[100];
%}
 
%left '+''-'
%left '*' '/'
%token STR OPEN COND INIT WHILE CLOSE SO SC
 
%%
prog : prog WHILE SO COND SC OPEN expr CLOSE '\n' {strcpy(init,$4); printf("\n%c = %c\n\tif(%s)\ngoto label\n",p,p-1,init);}
|
;
expr : STR
| expr '+' expr {if(l==0){printf("label\n%s",init);l=1;} if(i==0){ printf("%c = %d %c %d\n",p,$1,'+',$3); p++;i++;$$=p;}
else{ printf("%c = %c %c %d\n",p,p-1,'+',$3);p++;}}
| expr '-' expr {if(l==0){printf("label\n%s",init);l=1;} if(i==0){ printf("%c = %d %c %d\n",p,$1,'-',$3); p++;i++;$$=p;}
else{ printf("%c = %c %c %d\n",p,p-1,'-',$3);p++;}}
| expr '*' expr {if(l==0){printf("label\n%s",init);l=1;} if(i==0){ printf("%c = %d %c %d\n",p,$1,'*',$3); p++;i++;$$=p;}
else{ printf("%c = %c %c %d\n",p,p-1,'*',$3);p++;}}
| expr '/' expr {if(l==0){printf("label\n%s",init);l=1;} if(i==0){ printf("%c = %d %c %d\n",p,$1,'/',$3); p++;i++;$$=p;}
else{ printf("%c = %c %c %d\n",p,p-1,'/',$3);p++;}}
;
%%
 
void yyerror(char *s)
{
printf("%s\n",s);
}
 
int main()
{
yyparse();
return 0;
}

