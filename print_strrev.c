#include "main.h"


/**
 * print_strrev - print string in reverse
 * @r - string
 * Return: strlen
 */

int print_strrev(va_list r)
{
	char *s;
	int i, len;

	s = va_arg(r, char *);

	if (s == NULL)
		s = "(null)";

	len = 0;
	while (s[len] != '\0')
		++len;

	for (i = len - 1; i >= 0; --i)
		_putchar(s[i]);

	return (len);
}
