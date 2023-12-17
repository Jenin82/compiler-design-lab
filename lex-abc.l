%{
#include <stdio.h>
int vowel = 0, consonant = 0;
%}

%option noyywrap

%%
[a] {
    printf("A");
}
[b] {
	printf("B");
}
[c] {
	printf("C");
}
[a-zA-Z] {
	printf("%s",yytext);
}
\n {
    //fgdg
}
. {
    //do nothing
}
%%

void main() {
    printf("Enter a string.\n");
    while(1) {
        yylex();
    }
}