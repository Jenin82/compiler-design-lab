%{
#include "y.tab.h"	
%}

%option noyywrap

%%
[0-9]+[+\-*/%][0-9]+ { return EXPRESSION; }
\-[0-9]+ { return MINUS; }
[0-9]+ { return PLUS; }
\([0-9]+[+\-*/%][0-9]+\)|\(\-[0-9]+\)|\([0-9]+\) {return BRACKET; }
[0-9]+[+\-*/%] { return 0; }
\-[0-9]+[+\-*/%] { return 0; }
\n { return 0; }
. { return 0; }
%%