%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
"if" {return NUMBER;}
"}" {return BRACKET;}
. {;}
%%
int yywrap(){
return 1;
}

