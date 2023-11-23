#include <stdio.h>
#include <ctype.h> // Needed for isalnum

char str[100];
int result = 1, i = 0;

void E();
void Eprime();
void T();
void Tprime();
void F();
void Fprime();
void B();
void Bprime();
void C();

void E()
{
	T();
	Eprime();
}

void Eprime()
{
	if (str[i] == '+')
	{
		i++;
		T();
		Eprime();
	}
}

void T()
{
	F();
	Tprime();
}

void Tprime()
{
	if (str[i] == '*')
	{
		i++;
		F();
		Tprime();
	}
}

void F()
{
	B();
	Fprime();
}

void Fprime()
{
	if (str[i] == '/')
	{
		i++;
		B();
		Fprime();
	}
}

void B()
{
	C();
	Bprime();
}

void Bprime()
{
	// Implement Bprime logic if needed
}

void C()
{
	if (isalnum(str[i]))
	{
		i++;
	}
	else if (str[i] == '(')
	{
		i++;
		E(); // Call E() here
		if (str[i] == ')')
		{
			i++;
		}
		else
		{
			result = 0;
		}
	}
	else
	{
		result = 0;
	}
}

int main()
{
	printf("Enter the string: \n");
	fgets(str, sizeof(str), stdin); // Safe alternative to gets
	E();
	if (result)
	{
		printf("The string is accepted\n");
	}
	else
	{
		printf("The string is not accepted\n");
	}
	return 0;
}
