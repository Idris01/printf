#include "main.h"


/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 * Return: 1.
 */

int print_string(va_list s)
{
	char *val;
	int  len;

	val = va_arg(s, char *);
	len = 0;

	if (val == NULL)
		val = "(null)";

	while (val[len])
	{
		_putchar(val[len]);
		len++;
	}

	return (len);
}
