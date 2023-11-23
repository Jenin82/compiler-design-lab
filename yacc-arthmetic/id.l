%{
#include "y.tab.h"	
%}

%option noyywrap

%%
[0-9]+|\(\-[0-9]+\) { return NUMBER; }
[+\-*/%] { return OPERATOR; }
"(" { return LPAREN; }
")" { return RPAREN; }
\n { return 0; }
. { return 0; }
%%