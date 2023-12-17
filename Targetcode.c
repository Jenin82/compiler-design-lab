#include <stdio.h>
#include <string.h>
int main()
{
	int c = 0;
	char res[100], ar1[100], op1[100], op2[100], ar2[100];
	FILE *fp1, *fp2;
	fp1 = fopen("in.txt", "r");
	fp2 = fopen("out.txt", "w");
	while (!feof(fp1))
	{
		fscanf(fp1, "%s%s%s%s%s", res, op1, ar1, op2, ar2);
		fprintf(fp2, "mov r%d , %s\n", c, ar1);
		if (strcmp("+", op2) == 0)
			fprintf(fp2, "add r%d , %s\n", c, ar2);
		if (strcmp("-", op2) == 0)
			fprintf(fp2, "sub r%d , %s\n", c, ar2);
		if (strcmp("*", op2) == 0)
			fprintf(fp2, "mul r%d , %s\n", c, ar2);
		if (strcmp("/", op2) == 0)
			fprintf(fp2, "div r%d , %s\n", c, ar2);
		fprintf(fp2, "mov %s,r%d\n", res, c);
		fscanf(fp1, "%s%s%s%s%s", res, op1, ar1, op2, ar2);
		c++;
	}
}
