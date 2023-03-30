#include "main.h"
/**
 * print_octal - octal print
 * @args: argument
 * Return: number
 */
int print_octal(va_list args)
{
	unsigned int x;
	int i = 1, j = 0, k = 0;
	char oct[12];

	x = va_arg(args, unsigned int);
	if (x == 0)
	{
		writetostdout('0');
		return (1);
	}
	while (x > 0)
	{
		oct[i++] = x % 8 + '0';
		x = x / 8;
		k++;
	}
	for (j	= i - 1; j > 0; j--)
		writetostdout(oct[j]);
	return (k);
}
/**
 * print_upper_hexa - hexa decimal
 * @args: param
 * Return: length
 */
int print_upper_hexa(va_list args)
{
	unsigned int quo;
	int i = 1, j, k = 0, temp;
	char hexadecNum[100];

	quo = va_arg(args, unsigned int);
	if (quo == 0)
	{
		writetostdout('0');
		return (1);
	}
	while (quo != 0)
	{
		temp = quo % 16;
		temp += (temp < 10) ? 48 : 55;
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
	unsigned int quo;
	int i = 1, j, k = 0, temp;
	char hexadecNum[100];

	quo = va_arg(args, unsigned int);
	if (quo == 0)
	{
		writetostdout('0');
		return (1);
	}
	while (quo != 0)
	{
		temp = quo % 16;
		temp += (temp < 10) ? 48 : 87;
		hexadecNum[i++] = temp;
		quo = quo / 16;
		k++;
	}
	for (j = i - 1; j > 0; j--)
		writetostdout(hexadecNum[j]);
	return (k);
}
/**
 * print_pointer - print pointer
 * @args: argument
 * Return: number of char
 */
int print_pointer(va_list args)
{
	unsigned long x;
	int i = 2, j, temp, k = 0;
	char hexadecNum[100];
	void *quo = va_arg(args, void *);

	x = (unsigned long)quo;
	if (x == 0)
	{
		writetostdout('0');
		return (1);
	}
	while (x != 0)
	{
		temp = x % 16;
		temp += (temp < 10) ? 48 : 87;
		hexadecNum[i++] = temp;
		x /= 16;
	}
	for (j = i - 1; j >= 2; j--)
		writetostdout(hexadecNum[j]);
	return (k);
}
