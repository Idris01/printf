#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

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


int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list val);
int print_string(va_list val);


#endif /* MAIN_H */
