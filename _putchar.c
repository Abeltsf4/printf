#include "main.h"
/**
 * writetostdout - writes to standard output
 * @c: given character
 * Return: number of character
 */
char writetostdout(char c)
{
	return (write(1, &c, 1));
}
