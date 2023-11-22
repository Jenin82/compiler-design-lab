%{
#include <stdio.h>
int valid=1;
%}

%token MINUS
%token PLUS
%token EXPRESSION
%token BRACKET

%%
E: EXPRESSION
	| MINUS
	| PLUS
	| BRACKET
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