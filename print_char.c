#include "main.h"


/**
 * print_char - writes the character c to stdout
 *
 * @c: The character to print
 *
 * Return: 1.
 */

int print_char(va_list val)
{
	unsigned char c;

	c = va_arg(val, int);

	_putchar(c);

	return (1);
}
