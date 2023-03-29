#include "main.h"
/**
 * print_octal - octal print
 * @args: argument
 * Return: number
 */
int print_octal(va_list args)
{
	unsigned int x = 0;
	int i = 0, j = 0;

	x = va_arg(args, int);
	j = x;
	if (j < 0)
	{
		j *= -1;
		x = j;
	}
	while (j > 0)
	{
		j /= 8;
		i++;
	}
	recursion_octal(x);
	return (i);
}
/**
 * recursion_octal - octal
 * @x: parm
 */
void recursion_octal(unsigned int x)
{
	if (x / 8)
		recursion_octal(x / 8);
	writetostdout(x % 8 + '0');
}
