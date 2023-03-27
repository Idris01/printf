#include "main.h"

/**
 * _printf - Print formated string
 * @format: pointer to string
 * Return: integer the number of printed characters
 */

int _printf(const char *format, ...)
{
	va_list arguments;
	int size, index = 0, char_count = 0, counter, flag = 0;
	char pres_char;
	func format_func[] = {{"c", _print_char}, {"s", _print_str},
		{"i", _print_int}, {"d", _print_int}, {NULL, NULL}};


	if (format == NULL) /* || (format[0] == '%' && format[1] == '\0')) */
		return (char_count);

	size = strlen(format);
	va_start(arguments, format);
	for (; index < size; index++)
	{
		pres_char = format[index];
		if (flag) /* the character at format[index - 1] is '%' */
		{
			counter = 0;
			for (; counter >= 0; counter++)
			{
				if (format_func[counter].c == NULL)
				{	/* format is not defined hence print both the flag and the pres_char */
					char_count += _print_ord_char(format + (index - 1));
					char_count += _print_ord_char(format + index);
					break;
				}
				else if (*(format_func[counter].c) == pres_char)
				{
					char_count += format_func[counter].f((void *)&arguments);
					break;
				}
			}
			flag = 0;
		}
		else if (pres_char == '%')
			flag = 1;
		else
			char_count += _print_ord_char(format + index);
	}
	va_end(arguments); /* release the memory */
	return (char_count);
}
