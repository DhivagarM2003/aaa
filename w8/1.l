%{
#include <stdio.h>
#include "y.tab.h"
extern int yylval;
%}
%%
"{" {return NUMBER;}
"}" {return BRACKET;}
. {;}
%%
int yywrap(){
return 1;
}

