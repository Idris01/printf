#ifndef MAIN_H
#define MAIN_H


#include <string.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdbool.h>
#include <stdarg.h>

/**
 * struct Func - Define format char c and its
 * corresponding function f
 * @c: pointer to character
 * @f: pointer to function that prints next argument in va_list
 */

struct Func
{
	char *c;
	int (*f)(const va_list *);
};
typedef struct Func func;

int print_digit(int n);
int _print_ord_char(const char *c);
int _printf(const char *format, ...);
int _print_char(const va_list *list);
int _print_int(const va_list *list);
int _print_str(const va_list *list);

#endif
