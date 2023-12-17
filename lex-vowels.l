%{
#include <stdio.h>
int vowel = 0, consonant = 0;
%}

%option noyywrap

%%
[aeiouAEIOU] {
    vowel++;
}
[a-zA-Z] {
	consonant++;
}
\n {
    printf("Vowels: %d\nConsonants: %d\n", vowel, consonant);
    vowel = 0;
    consonant = 0;
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