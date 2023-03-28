#include "main.h"


/**
* print_bin - convert to binary
* @b: number in decinal
* Return: number of chars printed
*/

int print_bin(va_list b)
{
	unsigned int len;
	unsigned powten, index, digit, val, num;
	int count;

	count = 0;

	val = va_arg(b, unsigned int);
	if (val != 0)
	{
		num = val;
		len = 0;
		while (num != 0)
		{
			num /= 2;
			len++;
		}
		powten = 1;
		for (index = 1; index <= len - 1; index++)
			powten *= 2;
		for (index = 1; index <= len; index++)
		{
			digit = val / powten;
			_putchar(digit + '0');
			count++;
			val -= digit * powten;
			powten /= 2;
		}
	}
	else
	{
		_putchar('0');
		return (1);
	}
	return (count);
}
