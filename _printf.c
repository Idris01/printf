#include "main.h"
#include "match_specifier_to_function.h"

/**
 * _printf - is a function that formats and prints data
 *
 * @format: identifier to look for - (char, string, int)
 *
 * Return: the length of the output string.
 */

int _printf(const char * const format, ...)
{
	va_list arguments;
	int (*f)(va_list);
	unsigned int len = 0;

	int i;

	if (format == NULL)
		return (-1);

	va_start(arguments, format);
	len = 0;

	i = 0;
	while (format[i])
	{
		/* For ordinary characters */
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			++len;
			++i;
		}

		/* If the string is completely ordinary, we should reach the end and return. */
		if (format[i] == '\0')
			return (len);

		/* If you reach here, the string has format specifiers... */
		/* We will attempt to find and match them... */
		f = match_specifier_to_function(&format[i + 1]);
		/* The above line sends the format specifier to the function dictionary */
		/* and get the function we need to send it to. */

		/* If we dont match any, `f' is NULL */

		/* In this case, we find a match and perform calculations accordingly */
		if (f != NULL)
		{
			/* Add the result to th string length `len' */
			len += f(arguments);
			i += 2;
			continue;
		}

		/* If this next character is empty */
		if (!format[i + 1])
			return (-1);

		/* We have a percentage therefore _putchar it and increase string length */
		_putchar(format[i]);
		++len;

		/* Since we have used one '%', let's remove the other and continue */
		if (format[i + 1] == '%')
			i += 2;
		else
			++i;
	}

	va_end(arguments);

	return (len);
}
