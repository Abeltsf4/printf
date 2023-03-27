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
