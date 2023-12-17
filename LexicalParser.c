#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int isKeyword(char buffer[])
{
	char keywords[32][10] = {"auto", "break", "case", "char", "const", "continue", "default",
							 "do", "double", "else", "enum", "extern", "float", "for", "goto",
							 "if", "int", "long", "register", "return", "short", "signed",
							 "sizeof", "static", "struct", "switch", "typedef", "union",
							 "unsigned", "void", "volatile", "while"};
	int i, flag = 0;
	for (i = 0; i < 32; ++i)
	{
		if (strcmp(keywords[i], buffer) == 0)
		{
			flag = 1;
			break;
		}
	}
	return flag;
}

int isNumeric(const char *str)
{
	for (int i = 0; str[i] != '\0'; i++)
	{
		if (!isdigit(str[i]))
			return 0;
	}
	return 1;
}

int main()
{
	char ch, buffer[15], operators[] = "+-*/%=";
	FILE *fp;
	int i, j = 0;
	fp = fopen("input.txt", "r");
	if (fp == NULL)
	{
		printf("error while opening the file\n");
		exit(0);
	}
	while ((ch = fgetc(fp)) != EOF)
	{
		for (i = 0; i < 6; ++i)
		{
			if (ch == operators[i])
				printf("%c is operator\n", ch);
		}
		if(ch == '(' || ch == ')' || ch == '[' || ch == ']' || ch == '{' || ch == '}' || ch == ';')
			printf("%c is symbol\n", ch);
		if (isalnum(ch))
		{
			buffer[j++] = ch;
		}
		else if ((ch == ' ' || ch == '\n') && (j != 0))
		{
			buffer[j] = '\0';
			j = 0;
			if (isNumeric(buffer))
				printf("%s is constant\n", buffer);
			else if (isKeyword(buffer) == 1)
				printf("%s is keyword\n", buffer);
			else
				printf("%s is identifier\n", buffer);
		}
	}
	fclose(fp);
	return 0;
}