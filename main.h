#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list val);
int print_string(va_list val);
int print_dec(va_list val);
int print_int(va_list val);


/**
  * struct code_format - Struct format
  *
  * @sc: The specifiers
  * @f: The function associated
  */

typedef struct code_format
{
	char *sc;
	int (*f)(va_list);
} code_f;

#endif /* MAIN_H */
