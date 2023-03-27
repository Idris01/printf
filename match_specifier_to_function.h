#ifndef MATCH_SPECIFIER_TO_FUNCTION_H
#define MATCH_SPECIFIER_TO_FUNCTION_H


#include "main.h"


/**
  * struct specifier_dict - struct format - structure for dictionary containing specifier
  * and their respective functions
  *
  * @specifier: type char pointer of the specifier - could be c, s or %
  * @function: type pointer to function for the conversion specifier
  */

typedef struct format
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
	unsigned int i;

	specifier_dict dict[] = {
		{"c", print_char},
		{"s", print_string},
		{NULL, NULL}
	};

	i = 0;
	while (dict[i].specifier)
	{
		if (dict[i].specifier[0] == (*format))
			return (dict[i].function);
		i++;
	}
	return (NULL);
}


#endif /* MATCH_SPECIFIER_TO_FUNCTION_H */
