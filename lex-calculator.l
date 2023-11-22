%{
#include <stdio.h>
#include <stdlib.h>
double result = 0.0;
double current_number = 0.0;
char last_operator = 0;
%}

%option noyywrap

%%
[0-9]+(\.[0-9]+)? {
    current_number = atof(yytext);
    if (last_operator) {
        switch(last_operator) {
            case '+': result += current_number; break;
            case '-': result -= current_number; break;
            case '*': result *= current_number; break;
            case '/': 
                if (current_number != 0) {
                    result /= current_number; 
                } else {
                    printf("Error: Division by zero\n");
                }
                break;
        }
        last_operator = 0;
    } else {
        result = current_number;
    }
}
[+\-*/] {
    last_operator = yytext[0];
}
\n {
    printf("Result: %f\n", result);
    result = 0;
    last_operator = 0;
}
. {
    // Handle invalid characters
    printf("Invalid character: %s\n", yytext);
}
%%

void main() {
    printf("Calculator. Enter expressions with +, -, *, /.\n");
    printf("Enter a new line to get the result. To exit, press Ctrl+C.\n");
    while(1) {
        yylex();
    }
}