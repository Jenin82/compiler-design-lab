#include <stdio.h>
#include <ctype.h>

int i = 0, flag=1;
char str[100];

void E() {
	T();
	Eprime();
}

void Eprime() {
	if(str[i] == '+' || str[i] == '-') {
		i++;
		T();
		Eprime();
	}
}

void T() {
	F();
	Tprime();
}

void Tprime() {
	if(str[i] == '*' || str[i] == '/') {
		i++;
		F();
		Tprime();
	}
}

void F() {
	if(isalnum(str[i])) {
		i++;
	} else {
		if(str[i] == '(') {
			i++;
			E();
			if(str[i] == ')') {
				i++;
			} else
				flag = 0;
		} else
			flag = 0;
	}
}

void main() {
	printf("Enter the expression\n");
	fgets(str, sizeof(str), stdin);
	E();
	if(flag) {
		printf("The expression is valid\n");
	} else {
		printf("The expression is invalid\n");
	}
}