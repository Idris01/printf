#include "main.h"


/**
 * print_int - prints integer
 * @i: integer to print
 * Return: number of characters printed
 */

int print_int(va_list i)
{
	int len, exp, index, digit, n, num, count = 0;

	n = va_arg(i, int);
	if (n != 0)
	{
		if (n < 0)
		{
			_putchar('-');
			count++;
		}
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
			if (n < 0)
				_putchar((digit * -1) + 48);
			else
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
