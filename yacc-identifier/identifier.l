%{
#include "y.tab.h"
%}

%option noyywrap

%%
[a-zA-Z]([a-zA-Z_0-9])* { return IDENTIFIER; }
\n { return 0; }
. { return 0; }
%%