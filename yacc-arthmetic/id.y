%{
#include <stdio.h>
int valid=1;
%}

%token NUMBER
%token OPERATOR
%token LPAREN
%token RPAREN

%%
expression
    : expression OPERATOR expression
    | LPAREN expression RPAREN
    | NUMBER
    ;
%%

void yyerror() {
    printf("Invalid\n\b");
	valid=0; 
}

void main() {
    printf("Enter the expression: ");
    yyparse();
	if(valid) {	
		printf("Valid\n");
    }
}