#include "main.h"


/**
 * print_S_helper - helper to print_S
 * @num: number to print.
 * Return: cnt.
 */

int print_S_helper(unsigned int num)
{
	unsigned int uf_d = num;

	int *arr;
	int idx, cnt = 0;

	while (num / 16 != 0)
	{
		num /= 16;
		cnt++;
	}
	cnt++;

	arr = malloc(cnt * sizeof(int));

	for (idx = 0; idx < cnt; idx++)
	{
		arr[idx] = uf_d % 16;
		uf_d /= 16;
	}
	for (idx = cnt - 1; idx >= 0; idx--)
	{
		if (arr[idx] > 9)
			arr[idx] = arr[idx] + 7;
		_putchar(arr[idx] + '0');
	}

	free(arr);

	return (cnt);
}


/**
 * print_S_str - prints S_str
 * @S: char *
 * Return: string length
 */

int print_S_str(va_list S)
{
	int net, i, len = 0;
	char *s = va_arg(S, char *);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i] != '\0'; i++)
	{
		if (s[i] < 32 || s[i] >= 127)
		{
			_putchar('\\');
			_putchar('x');
			len = len + 2;
			net = s[i];
			if (net < 16)
			{
				_putchar('0');
				len++;
			}
			len = len + print_S_helper(net);
		}
		else
		{
			_putchar(s[i]);
			len++;
		}
	}
	return (len);
}

