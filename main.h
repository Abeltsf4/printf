#ifndef PRINTF
#define PRINTF
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
/**
  * struct specifiers - Struct specifiers
  * @specifier: The conversion specifier
  * @f: The function pointer
  */
typedef struct specifiers
{
	char *specifier;
	int (*f)(va_list args);
} ft_dt;
int _printf(const char *format, ...);
char writetostdout(char c);
int _print(const char *f, va_list args);
int valid_format(char c);
int _print_det(char f, va_list args);
int _print_invalid_format(char prev, char format, int count);
int print_a_char(va_list args);
int print_a_string(va_list args);
int print_a_integer(va_list args);
void recursion_integer(int c);
int print_a_binary(va_list args);
void recursion_int_binary(int c);
#endif
