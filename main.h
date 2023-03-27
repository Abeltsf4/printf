#ifndef PRINTF
#define PRINTF
#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
int _printf(const char *format, ...);
int _print(char *f, char *args);
int valid_format(char c);
int _print_det(char f, va_list args);
int _print_invalid_format(char prev, char format, int count);
int print_a_char(va_list args);
int print_a_string(va_list args);
#endif
