#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

/**
 * print_digit - Helper function to print a positive  number
 * @n: Number to print
 *
 * Return: integer number of digits printed
 */

int print_digit(int n)
{
	int rem = abs(n % 10);
	int div = abs(n / 10);
	char c = '0' + rem;
	int print_count;

	if (div == 0)
	{
		write(1, &c, 1);
		return (1);
	}
	print_count = 1 +  print_digit(div);
	write(1, &c, 1);
	return (print_count);
}

/**
 * _print_char - Prints the next character in list argument
 * @list: pointer to va_list
 *
 * Return: integer return 1
 */

int _print_char(const va_list *list)
{
	char c = va_arg(*list, int);

	write(1, &c, 1);
	return (1);
}

/**
 * _print_str - Print the next string argument in list argument
 * @list: pointer to va_list
 *
 * Return: integer size of the printed string
 */

int _print_str(const va_list *list)
{
	int size;
	char *str = va_arg(*list, char *);

	if (str == NULL)
		return (0);
	size = strlen(str);
	write(1, str, size);
	return (size);
}

/**
 * _print_ord_char - Print a single character c
 * @c: pointer to an ordinary character
 *
 * Return: integer return 0 if c is NULL else 1
 */

int _print_ord_char(const char *c)
{
	if (c == NULL)
		return (0);
	write(1, c, 1);
	return (1);
}

/**
 * _print_int - Print the next string argument in list argument
 * @list: pointer to va_list
 *
 * Return: integer size of the printed string
 */

int _print_int(const va_list *list)
{
	char c;
	int count = 0, num = va_arg(*list, int);

	if (num < 0)
	{
		c = '-';
		write(1, &c, 1);
		count++;
	}
	count += print_digit(abs(num));
	return (count);
}


