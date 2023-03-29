#include "main.h"
/**
 * printBin - d
 * @args: ar
 * Return: c
 */
int printBin(va_list args)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	n = va_arg(args, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			writetostdout(z);
			count++;
		}
	}
	return (count);
}

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
		new = new * -1;
		x = new;
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
/**
 * print_unsigned_integer - print unsigned integer
 * @args: argument
 * Return: count
 */
int print_unsigned_integer(va_list args)
{
	unsigned int x = 0;
	int i = 0, j = 0;

	x = va_arg(args, int);
	j = x;
	while (x > 0)
	{
		x /= 10;
		i++;
	}
	recursion_integer(j);
	return (i);
}
