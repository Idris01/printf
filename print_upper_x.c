#include "main.h"


/**
 * print_X - prints it in uppercase hex
 * @X: unsigned int
 * Return: count
 */

int print_X(va_list X)
{
	return (print_hex(va_arg(X, unsigned int), 1));
}
