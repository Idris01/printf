#include "main.h"
#include "match_specifier_to_function.h"


/**
 * _printf - is a function that formats and prints data
 * @format: identifier to look for - (char, string, int)
 * Return: the no_of_char_printedgth of the output string.
 */

int _printf(const char *format, ...)
{
	va_list args;
	int (*printed_count_getter)(va_list);
	unsigned int no_of_char_printed = 0, index;

	if (format == NULL)
		return (-1);

	va_start(args, format);
	for (index = 0; format[index]; )
	{
		while (format[index] != '%' && format[index])
		{
			_putchar(format[index]);
			no_of_char_printed++;
			index++;
		}
		if (format[index] == '\0')
			return (no_of_char_printed);

		printed_count_getter = match_specifier_to_function(&format[index + 1]);
		if (printed_count_getter != NULL)
		{
			no_of_char_printed += printed_count_getter(args);
			index += 2;
			continue;
		}
		if (!format[index + 1])
			return (-1);
		_putchar(format[index]);
		no_of_char_printed++;
		if (format[index + 1] == '%')
			index += 2;
		else
			index++;
	}
	va_end(args);

	return (no_of_char_printed);
}
