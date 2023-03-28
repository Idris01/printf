#include "main.h"


/**
* print_unsigned - print unsigned integer
* @u: unsigned integer to print
* Return: number of characters printed
*/

int print_unsigned(va_list u)
{
	unsigned int len, exp, index, digit, n, num;
	int count = 0;

	n = va_arg(u, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 10;
			len++;
		}
		exp = 1;
		for (index = 1; index <= len - 1; index++)
			exp *= 10;
		for (index = 1; index <= len; index++)
		{
			digit = n / exp;
			_putchar(digit + '0');
			count++;
			n -= digit * exp;
			exp /= 10;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}

