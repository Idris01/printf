#include "main.h"

/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 * Return: 1.
 */

int print_string(va_list s)
{
	char *val;
	int  len = 0;

	val = va_arg(s, char *);

	if (val == NULL)
		val = "(null)";

	while (val[len])
	{
		_putchar(val[len]);
		i++;
	}

	return (len);
}
