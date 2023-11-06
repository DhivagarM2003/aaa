%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
"+"|"-"|"*"|"/" {return OP;}
[0-9] {return NUM;}
. {;}
%%
int yywrap(){
return 1;
}

