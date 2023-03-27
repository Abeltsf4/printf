#include "main.h"
/**
 * writestdout - writes to standard output
 * @c: given character
 * Return: number of character
 */
char writestdout(char c)
{
	return (write(1, &c, 1));
}
