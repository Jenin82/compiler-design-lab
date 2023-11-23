#include <stdio.h>
#include <string.h>

char a[20], stk[20];
int i, j = 0, c;

void check();

void main() {
	puts("GRAMMAR is E->E+E\n E->E-E\n E->E*E\n E->(E)\n E->id");
	puts("Enter input string:");
	scanf("%s", a);
	c = strlen(a);
	puts("stack \t input \t action");
	for (i = 0; j < c;) {
		if (a[j] == 'i' && a[j + 1] == 'd') {
			stk[i] = 'E';
			stk[i + 1] = '\0';
			printf("$%s\t%s$\tSHIFT->id\n", stk, a + j);
			i++;
			j += 2;
		} else {
			stk[i] = a[j];
			stk[i + 1] = '\0';
			printf("$%s\t%s$\tSHIFT->%c\n", stk, a + j, a[j]);
			i++;
			j++;
		}
		check();
	}
	while (i > 1) 
		check();
}

void check() {
	if (i >= 3 && stk[i - 1] == 'E' &&
	(stk[i - 2] == '+' || stk[i - 2] == '-' ||
	stk[i - 2] == '*' || stk[i - 2] == '/') &&
	stk[i - 3] == 'E') {
		stk[i - 3] = 'E';
		stk[i - 2] = '\0';
		i -= 2;
		printf("$%s\t%s$\tREDUCE TO E\n", stk, a + j);
	} else if (i >= 3 && stk[i - 1] == ')' && stk[i - 2] == 'E' && stk[i - 3] == '(') {
		stk[i - 3] = 'E';
		stk[i - 2] = '\0';
		i -= 2;
		printf("$%s\t%s$\tREDUCE TO E\n", stk, a + j);
	}
}