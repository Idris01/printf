#include "main.h"


/**
 * print_char - writes the character c to stdout
 * @c: character to print
 * Return: 1.
 */

int print_char(va_list c)
{
	unsigned char val;

	val = va_arg(c, int);

	_putchar(val);

	return (1);
}
