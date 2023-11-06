%option noyywrap

%%

"/*"    {int c;
        while(1){
                while((c=input())!='*' && c!=EOF);
                if(c=='*'){
                        while((c=input())=='*');
                if(c=='/')break;
                if(c==EOF){perror("EOF");}
        }}}

%%

int main(){
        yylex();
        return 0;
}

