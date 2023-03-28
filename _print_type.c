#include "main.h"

/**
  * print_a_char - Prints a char
  * @args: A list of variadic arguments
  * Return: The length of the character
  */
int print_a_char(va_list args)
{
	writetostdout(va_arg(args, int));
	return (1);
}

/**
  * print_a_string - Prints a string
  * @args: A list of variadic arguments
  * Return: The length of the string
  */
int print_a_string(va_list args)
{
	char *arg = va_arg(args, char *);
	int i = 0;

	if (arg != NULL)
	{
		while (arg[i])
		{
			writetostdout(arg[i]);
			i++;
		}

		return (i);
	}

	writetostdout('(');
	writetostdout('n');
	writetostdout('u');
	writetostdout('l');
	writetostdout('l');
	writetostdout(')');
	return (6);
}
/**
  * print_a_integer - Prints a integer
  * @args: A list of variadic arguments
  * Return: The length of the string
  */
int print_a_integer(va_list args)
{
	int count = 1, m = 0;
	unsigned int n = 0;

	n = va_arg(args, int);
	m = n;
	if (m < 0)
	{
		writetostdout('-');
		m = m * -1;
		n = m;
		count += 1;
	}
	while (n > 9)
	{
		n = n / 10;
		count++;
	}

	recursion_integer(m);
	return (count);
}

/**
  * recursion_integer - Prints a integer
  * @a: integer to print
  * Return: Nothing
  */
void recursion_integer(int a)
{
	unsigned int t;

	t = a;
	if (t / 10)
		recursion_integer(t / 10);
	writetostdout(t % 10 + '0');
}
