#include "main.h"


/**
 * print_string - writes the character c to stdout
 * @s: The string to print
 *
 * Return: 1.
 */

int print_string(va_list val)
{
	char *s;
	int  len = 0;

	s = va_arg(val, char *);

	if (s == NULL)
		s = "(null)";

	while (s[len])
	{
		_putchar(s[len]);
		len++;
	}
	return (len);
}
