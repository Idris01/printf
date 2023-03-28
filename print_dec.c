#include "main.h"


/**
* print_dec - function that prints an decimal
* @d: integer to print
* Descriptions: prints digit with _putchar
* Return: size the output text
*/

int print_dec(va_list d)
{
	int len, exp, index, digit, n, count = 0, num;

	n = va_arg(d, int);
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
