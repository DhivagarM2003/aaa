%option noyywrap
%{
#include<stdio.h>
char initial[20],cond[20],update[20],block[100];
%}

%%
"for("  {
                char c;
                int l=0;
                while((c=input())!= ';' && c!=EOF)
                {
                        initial[l]=c;
                        l++;
                        }
                if(c==';'){
                        int i=0;
                        while ((c= input()) != ';'){
                                cond[i] = c;
                                i++;
                                }
                        int j=0;
                        while((c=input()) != ')'){
                                update[j] = c;
                                j++;
                        }
                        i=0;
                        while((c=input()) != '}'){
                                block[i] = c;
                                i++;
                        }
                }
        if  (c==EOF){
        perror("Syntax error\n");
        break;
        }
        }
%%

int main(){
yylex();
/*printf("\n%s;",initial);
//printf("\nWhile(%s)",cond);
printf("\nWhile(%s)\n%s\n%s;\n}\n",cond,block,update);*/
int i;
if (strlen(cond)<3){
printf("Infinite loop");
}
else if(cond[1]=='<' && update[1]=='-'){
printf("Infinite loop");
}
else if(cond[1]=='>' && update[1]=='+'){
printf("Infinite loop");
}
else if (initial[2]>cond[2] && update[1]=='+'){
printf("Infinite loop");
}
else if (initial[2]<cond[2] && update[1]=='-'){
printf("Infinite loop");
}
else 
printf("Finite loop");
return 0;
}

