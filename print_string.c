#include "main.h"


/**
 * print_string - prints a string to stdout
 *
 * @val: argument
 *
 * Return: the length of the string.
 */

int print_string(va_list val)
{
	char *s;
	int len;

	s = va_arg(val, char *);
	len = 0;

	if (s == NULL) {
		return (0);
		s = "(null)";
	}

	while (s[len])
	{
		_putchar(s[len]);
		++len;
	}

	return (len);
}
