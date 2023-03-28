#include "main.h"


/**
 * print_ptr_helper - help print_ptr
 * @num: number
 * Return: cnt.
 */

int print_ptr_helper(unsigned long int num)
{
	unsigned long int uf_d = num;

	long int *arr;
	long int i, cnt = 0;

	while (num / 16 != 0)
	{
		num /= 16;
		cnt++;
	}
	cnt++;

	arr = malloc(cnt * sizeof(long int));

	for (i = 0; i < cnt; i++)
	{
		arr[i] = uf_d % 16;
		uf_d /= 16;
	}
	for (i = cnt - 1; i >= 0; i--)
	{
		if (arr[i] > 9)
			arr[i] = arr[i] + 39;
		_putchar(arr[i] + '0');
	}

	free(arr);

	return (cnt);
}


/**
 * print_ptr - print a pointer in hexadecimals
 * @p: pointer
 * Return: cnt.
 */

int print_ptr(va_list p)
{
	void *val;
	char *s = "(nil)";
	long int helper;
	int result;
	int i;

	val = va_arg(p, void*);
	if (val == NULL)
	{
		for (i = 0; s[i] != '\0'; i++)
		{
			_putchar(s[i]);
		}
		return (i);
	}

	helper = (unsigned long int)val;
	_putchar('0');
	_putchar('x');
	result = print_ptr_helper(helper);
	return (result + 2);
}
