%{
#include<stdio.h>
char c[26];
int a[26]={0};
int b=0;
%}

%%
[a-z] {a[yytext[0]-'a']++;}
%%
int yywrap(){
return 1;
}
int main(){
printf("Enter the string: ");
yylex();
for(int i=0;i<26;i++){
if(a[i]==1){
c[b]=97+i;
b++;
}
}
printf("Distict: %d %s",b,c);
return 0;
}



