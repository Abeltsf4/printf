#include "main.h"
/**
 * print_octal - octal print
 * @args: argument
 * Return: number
 */
int print_octal(va_list args)
{
	unsigned int x = 0;
	int i = 0;

	x = va_arg(args, unsigned int);
	while (x > 0)
	{
		x /= 8;
		i++;
	}
	recursion_octa(x);
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
	writetostdout(x % 2 + '0');
}
