#include "main.h"

/**
 * _printf - Print formated string
 * @format: pointer to string
 *
 * Return: integer the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int size, index = 0, char_count = 0;
	bool flag = 0;
	char pres_char, *arg_string, arg_char;

	if (format == NULL)
		return (char_count);
	size = strlen(format);
	va_start(arguments, format);
	for (; index < size; index++)
	{
		pres_char = format[index];
		if (flag) /* the character at format[index - 1] is '%' */
		{
			switch (pres_char)
			{
				case 'c':
					arg_char = va_arg(arguments, int); /* char is promoted to int */
					char_count += _print_char(&arg_char);
					break;
				case 's':
					arg_string = va_arg(arguments, char *);
					char_count += _print_str(arg_string);
					break;
				case '%':
					char_count += _print_char(format + index);
					break;
				default:
					char_count += _print_char(format + (index - 1));
					char_count += _print_char(format + index);
			}
			flag = 0;
		}
		else if (pres_char == '%')
			flag = 1;
		else
			char_count += _print_char(format + index);
	}
	va_end(arguments); /* release the memory */
	return (char_count);
}
