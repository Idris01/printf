#include "main.h"


/**
 * print_x - prints it in lowercase hex
 * @x: unsigned int
 * Return: count
 */

int print_x(va_list x)
{
	return (print_hex(va_arg(x, unsigned int), 0));
}
