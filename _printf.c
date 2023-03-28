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
 * @format: format list
 * @args: argument
 * Return: number of character
 */
int _print(const char *format, va_list args)
{
	int c = 0;
	int i = 0;

	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			while (format[i] == ' ')
				i++;
			if (format[i] == '%')
				c += writetostdout('%');
			if (valid_format(format[i]))
				c += _print_det(format[i], args);
			else
				c += _print_invalid_format(format[i - 1], format[i], c);
		}
		else
			c += writetostdout(format[i]);
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
	char format_list[] = {'c', 's', 'd', 'i', 'b', '%'};

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
 * @format: format
 * @args: argument
 * Return: length of char
 */
int _print_det(char format, va_list args)
{
	int i  = 0, length = 0;
	ft_dt format_types[] = {
		{"c", print_a_char},
		{"s", print_a_string},
		{"d", print_a_integer},
		{"i", print_a_integer},
		{"b", print_int_binary}
		{NULL, NULL}
	};

	while (format_types[i].specifier)
	{
		if (*format_types[i].specifier == format)
			length = format_types[i].f(args);

		i++;
	}

	return (length);
}
/**
 * _print_invalid_format - print unknown format type
 * @prev_format: previous format type
 * @format: current format type
 * @c: character count
 * Return: character length
 */
int _print_invalid_format(char prev_format, char format, int c)
{
	c += writetostdout('%');

	if (prev_format == ' ')
	{
		c += writetostdout(' ');
		c += writetostdout(format);
	}
	else
		c += writetostdout(format);
	return (c);
}
