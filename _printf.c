#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>

/**
 * _printf - Print formated string
 * @format: pointer to string
 *
 * Return: integer the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int size, index, char_count = 0;
	bool flag = 0;
	char pres_char, *arg_string, arg_char;

	if (format == NULL)
		return (char_count);
	size = strlen(format);
	index = 0;
	va_start(arguments, format);
	for (; index < size; index++)
	{
		pres_char = format[index];
		if (flag) /* the character at format[index - 1] is '%' */
		{
			if (pres_char == 'c')
			{
				arg_char = va_arg(arguments, int); /* char is promoted to int */
				write(0, &arg_char, 1); /* print arg_char using its memory address */
				char_count++;
			}
			else if (pres_char == 's')
			{
				arg_string = va_arg(arguments, char *);
				write(0, arg_string, strlen(arg_string));
				char_count += strlen(arg_string);
			}
			else if (pres_char == '%')
			{
				write(0, format + index, 1);
				char_count++;
			}
			flag = 0;
		}
		else if (pres_char == '%')
			flag = 1;
		else
		{
			write(0, format + index, 1); /* get address at index */
			char_count++;
		}
	}
	va_end(arguments); /* release the memory */
	return (char_count);
}
