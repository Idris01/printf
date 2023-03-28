#include "main.h"


/**
* print_binary - decimal is converted to binary
* @b: unsigned integer to convert to binary
* print unsigned binary number
* Return: number of chars printed
*/

int print_bin(va_list b)
{
	unsigned int len;
	unsigned exp, index, digit, n, num;
	int count;

	count = 0;

	n = va_arg(b, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		exp = 1;
		for (index = 1; index <= len - 1; index++)
			exp *= 2;
		for (index = 1; index <= len; index++)
		{
			digit = n / exp;
			_putchar(digit + '0');
			count++;
			n -= digit * exp;
			exp /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
