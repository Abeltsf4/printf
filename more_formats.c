#include "main.h"
/**
 * print_a_binary - integer binary
 * @args: argument
 * Return: binary
 */
int print_a_binary(va_list args)
{
	unsigned int x = 0;
	int b = 0, new = 0;

	new = va_arg(args, int);
	x = new;
	if (new < 0)
	{
		writetostdout('1');
		new = new * -1;
		x = new;
		b += 1;
	}
	while (x > 0)
	{
		x = x / 2;
		b++;
	}
	recursion_int_binary(new);
	return (b);
}

/**
  * recursion_int_binary - Prints a binary
  * @a: integer to print
  *
  */
void recursion_int_binary(int a)
{
	unsigned int t;

	t = a;
	if (t / 2)
		recursion_int_binary(t / 2);
	writetostdout(t % 2 + '0');
}
