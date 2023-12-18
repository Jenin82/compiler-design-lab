%{
#include<stdio.h>
#include<stdlib.h>
     
int op = 0, i;
float a, b;

void digit() {
    if (op == 0) {
        a = atof(yytext);
    } else {
        b = atof(yytext);
    }
    switch (op) {
        case 1: a = a + b; break;
        case 2: a = a - b; break;
        case 3: a = a * b; break;
        case 4: a = a / b; break;
        case 5:
                for(i=1;i<b;i++){
                    a *=  a;
                }
                break;
             
    }
    op = 0;
}
%}

%option noyywrap

%%
[0-9]+("."[0-9]+)? { digit(); }
"+" { op = 1; }
"-" { op = 2; }
"*" { op = 3; }
"/" { op = 4; }
"^" { op = 5; }
\n { printf("\n Answer:%f\n\n", a); }
%%

int main() {
    yylex();
    return 0;
}
