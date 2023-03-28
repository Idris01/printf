#include "main.h"

/**
  * match_specifier_to_function - is function that finds formats for _printf
  * and matches it the corresponding function.
  *
  * @format: format (char, string, int, decimal)
  * Return: NULL or function associated ;
  */

int (*match_specifier_to_function(const char *format))(va_list)
{
	unsigned int i = 0;
	code_f dict[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}
	};

	while (dict[i].sc)
	{
		if (dict[i].sc[0] == (*format))
			return (dict[i].f);
		i++;
	}
	return (NULL);
}


/**
 * _printf - is a function that formats and prints data
 * @format: identifier to look for - (char, string, int)
 * Return: the length of the output string.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*f)(va_list);
	unsigned int i = 0, len = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			len++;
			i++;
		}
		if (format[i] == '\0')
			return (len);
		f = match_specifier_to_function(&format[i + 1]);
		if (f != NULL)
		{
			len += f(args);
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
