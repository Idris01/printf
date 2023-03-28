#include "main.h"


/**
* print_oct - decimal is converted to octal
* @o: unsigned integer to convert to octal
* print unsigned octal number
* Return: number of chars printed
*/

int print_oct(va_list o)
{
	unsigned int len, exp, index, digit, n, num;
	int count = 0;

	n = va_arg(o, unsigned int);
	if (n != 0)
	{
		num = n;
		len = 0;
		while (num != 0)
		{
			num /= 8;
			len++;
		}
		exp = 1;
		for (index = 1; index <= len - 1; index++)
			exp *= 8;
		for (index = 1; index <= len; index++)
		{
			digit = n / exp;
			_putchar(digit + '0');
			count++;
			n -= digit * exp;
			exp /= 8;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
