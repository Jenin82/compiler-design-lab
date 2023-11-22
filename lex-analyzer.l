%{
#include <stdio.h>
%}

%option noyywrap

%%
"for"|"int"|"while"|"char" { printf("%s is a Keyword\n",yytext); }
[a-zA-Z]+([0-9]+)?([a-zA-Z]+)? { printf("%s is an Identifier\n",yytext); }
[0-9]+ { printf("%s is a Constant\n",yytext); }
[:;{}()"'?,] { printf("%s is a Punctuation\n",yytext); }
[+\-/*%] { printf("%s is an Arthemetic Operator\n",yytext); }
"=="|"<="|">="|"<"|">" { printf("%s is a Relational Operator\n",yytext); }
"=" {printf("%s is an Assignment\n",yytext); }
\n { /* Ignore new lines */ }
. { /* Ignore other characters */ }
%%

int main() {
    printf("Enter text, words will be identified:\n");
    while(1) {
        yylex();
    }
    return 0;
}