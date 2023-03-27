#include "main.h"


/**
 * print_char - write char c to stdout
 *
 * @val: argument
 *
 * Return 1.
 */

int print_char(va_list val)
{
	unsigned char c;

	c = va_arg(val, int);

	if (c == NULL)
		return (0);

	_putchar(c);

	return (1);
}
