%{
#include <stdio.h>
int valid=1;
%}

%token IDENTIFIER

%%
statement: IDENTIFIER;
%%

void yyerror() {
    printf("Invalid identifier\n\b");
	valid=0; 
}

void main() {
    printf("Enter the variable name: ");
    yyparse();
	if(valid) {	
		printf("Valid identifier\n");
    }
}