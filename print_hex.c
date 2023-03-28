#include "main.h"


/**
* print_hex - print hexadecimal
* @n: unsigned integer to print
* @c: uppercase = 1, lowercase = 0
* Return: count of printed chars
*/

int print_hex(unsigned int n, unsigned int c)
{
	unsigned int len, exp, idx, dgt, num;
	int count = 0;
	char diff;

	if (n != 0)
	{
		num = n;
		len = 0;
		if (c)
			diff = 'A' - ':';
		else
			diff = 'a' - ':';
		while (num != 0)
		{
			num /= 16;
			len++;
		}
		exp = 1;
		for (idx = 1; idx <= len - 1; idx++)
			exp *= 16;
		for (idx = 1; idx <= len; idx++)
		{
			dgt = n / exp;
			if (dgt < 10)
				_putchar(dgt + '0');
			else
				_putchar(dgt + '0' + diff);
			count++;
			n -= dgt * exp;
			exp /= 16;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
