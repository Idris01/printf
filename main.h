#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_dec(va_list d);


/**
  * struct specifier_dict - struct format - structure for dictionary containing specifier
  * and their respective functions
  *
  * @specifier: type char pointer of the specifier - could be c, s or %
  * @function: type pointer to function for the conversion specifier
  */

typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;


#endif /* MAIN_H */
