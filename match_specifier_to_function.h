#ifndef MATCH_SPECIFIER_TO_FUNCTION_H
#define MATCH_SPECIFIER_TO_FUNCTION_H


#include "main.h"


/**
 * struct code_format - Struct format
 *
 *
 * @sc: The specifiers
 * @f: The function associated
 */

typedef struct code_format
{
	char *specifier;
	int (*function)(va_list);
} specifier_dict;


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
	specifier_dict dict[] = {
		{"c", print_char},
		{"s", print_string},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}
	};

	while (dict[i].specifier)
	{
		if (dict[i].specifier[0] == (*format))
			return (dict[i].function);
		i++;
	}
	return (NULL);
}


#endif /* MATCH_SPECIFIER_TO_FUNCTION_H */
