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
/**
 * print_upper_hexa - hexa decimal
 * @args: param
 * Return: length
 */
int print_upper_hexa(va_list args)
{
	unsigned long int quo;
	int i = 1, j, k = 0, temp;
	char hexadecNum[100];

	quo = va_arg(args, unsigned long int);
	while (quo != 0)
	{
		temp = quo % 16;
		if (temp < 10)
			temp = temp + 48;
		else
			temp = temp + 55;
		hexadecNum[i++] = temp;
		quo = quo / 16;
		k++;
	}
	for (j = i - 1; j > 0; j--)
		writetostdout(hexadecNum[j]);
	return (k);
}
/**
 * print_lower_hexa - hexa to lower
 * @args: arg
 * Return: length
 */
int print_lower_hexa(va_list args)
{
	unsigned long int quo;
	int i = 1, j, k = 0, temp;
	char hexadecNum[100];

	quo = va_arg(args, unsigned long int);
	while (quo != 0)
	{
		temp = quo % 16;
		if (temp < 10)
			temp += 48;
		else
			temp += 97;
		hexadecNum[i++] = temp;
		quo = quo / 16;
		k++;
	}
	for (j = i - 1; j > 0; j--)
		writetostdout(hexadecNum[j]);
	return (k);
}
