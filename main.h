#ifndef MAIN_H
#define MAIN_H


#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int _printf(const char *format, ...);
int _putchar(char c);
int print_char(va_list c);
int print_string(va_list s);
int print_int(va_list i);
int print_dec(va_list d);
int print_bin(va_list b);
int print_unsigned(va_list u);
int print_oct(va_list o);
int print_x(va_list x);
int print_X(va_list X);
int print_hex(unsigned int n, unsigned int c);
int print_strrev(va_list r);
int print_rot13(va_list R);
int print_S_str(va_list S);
int print_ptr(va_list p);


#endif /* MAIN_H */
