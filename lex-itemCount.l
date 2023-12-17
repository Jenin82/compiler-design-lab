%{
#include <stdio.h>
int space = 0, letter = 0, word=1, line=1;
%}

%option noyywrap

%%
[a-zA-Z] {
	letter++;
}
" " {
	space++;
	word++;
}
\n {
	word++;
	line++;
}
<<EOF>> {
    printf("\nSpaces: %d\nLetters: %d\nWords: %d\nLines: %d\n", space, letter, word, line);
    return 0;
}
. {
    //do nothing
}
%%

void main() {
    printf("Enter a string.\n");
    yylex();
}