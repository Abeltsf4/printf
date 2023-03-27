#include "main.h"
/**
 * _printf - printf feature
 * @format: given format
 * Return: number of character
 */
int _printf(const char *format, ...)
{
	int c = 0;
	va_list args;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	c = _print(format, args);
	va_end(args);
	return (c);
}
/**
 * _print - print as printf feature
 * @f: format list
 * @args: argument
 * Return: number of character
 */
int _print(char *f, char *args)
{
	int c = 0;
	int i = 0;

	while (f && f[i] != '\0')
	{
		if (f[i] == '%')
		{
			if (f[i + 1] == '\0')
				return (-1);
			i++;
			while (f[i] == ' ')
				i++;
			if (f[i] == '%')
				c += writestdout('%');
			if (valid_format(f[i]))
			{
				c += _print_det(f[i], args);
			}
			else
				c += _print_invalid_format(f[i - 1], f[i], c);
		}
		else
		{
			count += writetostdout(f[i]);
		}

		i++;
	}
	return (c);
}
/**
 * valid_format - validate format type
 * @c: given format
 * Return: 1 for Success 0. for fail
 */
int valid_format(char c)
{
	char format_list[] = {'c', 's'};

	int i = 0;

	while (format_list[i])
	{
		if (c == format_list[i])
			return (1);
		i++;
	}
	return (0);
}
/**
 * _print_det - determine which format type selected
 * @f: format
 * @args: argument
 * Return: length of char
 */
int _print_det(char f, va_list args)
{
	int i  = 0, length = 0;
	ft_dt format_types[] = {
		{"c", print_a_char},
		{"s", print_a_string},
		{NULL, NULL}
	};

	while (format_types[i].specifier)
	{
		if (*format_types[i].specifier == f)
			length = format_types[i].f(args);

		i++;
	}

	return (length);
}
/**
 * _print_invalid_format - print unknown format type
 * @prev_format: previous format type
 * @format: current format type
 * @count: character count
 * Return: character length
 */
int _print_invalid_format(char prev_format, char format, int count)
{
	count += writetostdout('%');

	if (prev_format == ' ')
	{
		count += writetostdout(' ');
		count += writetostdout(format);
	}
	else
	{
		count += writetostdout(format);
	}

	return (count);
}
