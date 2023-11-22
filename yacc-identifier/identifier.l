%{
#include "y.tab.h"
extern void yyerror();
%}

%option noyywrap

%%
[a-zA-Z]([a-zA-Z]|[0-9]|[_])* { return IDENTIFIER; }
\n { return 0; }
. { return 0; }
%%