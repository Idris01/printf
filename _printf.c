#include "main.h"
#include "match_specifier_to_function.h"


/**
 * _printf - is a function that formats and prints data
 * @format: identifier to look for - (char, string, int)
 * Return: the length of the output string.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*val)(va_list);
	unsigned int len = 0, i;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (i = 0; format[i]; )
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			len++;
			i++;
		}
		if (format[i] == '\0')
			return (len);

		val = match_specifier_to_function(&format[i + 1]);
		if (val != NULL)
		{
			len += val(args);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		len++;
		if (format[i + 1] == '%')
			i += 2;
		else
			i++;
	}
	va_end(args);

	return (len);
}
