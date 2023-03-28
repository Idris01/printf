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
	long int idx, cnt = 0;

	while (num / 16 != 0)
	{
		num /= 16;
		cnt++;
	}
	cnt++;

	arr = malloc(cnt * sizeof(long int));

	for (idx = 0; idx < cnt; idx++)
	{
		arr[idx] = uf_d % 16;
		uf_d /= 16;
	}
	for (idx = cnt - 1; idx >= 0; idx--)
	{
		if (arr[idx] > 9)
			arr[idx] = arr[idx] + 39;
		_putchar(arr[idx] + '0');
	}

	free(arr);

	return (cnt);
}


/**
 * print_ptr - print a pointer
 * @p: pointer
 * Return: cnt.
 */

int print_ptr(va_list p)
{
	void *val;
	char *s = "(nil)";
	int result, idx;

	val = va_arg(p, void*);
	if (val == NULL)
	{
		for (idx = 0; s[idx] != '\0'; idx++)
		{
			_putchar(s[idx]);
		}
		return (idx);
	}

	_putchar('0');
	_putchar('x');
	result = print_ptr_helper((unsigned long int)val);
	return (result + 2);
}

