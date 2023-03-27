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
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			++len;
			++i;
		}

		if (format[i] == '\0')
			return (len);

		f = match_specifier_to_function(&format[i + 1]);

		if (f != NULL)
		{
			len += f(arguments);
			i += 2;
			continue;
		}

		if (!format[i + 1])
			return (-1);

		_putchar(format[i]);
		++len;

		if (format[i + 1] == '%')
			i += 2;
		else
			++i;
	}

	va_end(arguments);

	return (len);
}
