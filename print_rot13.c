#include "main.h"


/**
 * printf_rot13 - printf str to ROT13
 * @R: string
 * Return: strlen
 */

int printf_rot13(va_list R)
{
	char *s;
	int i, j, flag = 0;
	int count = 0;

	char P[] = {"abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ"};
	char Q[] = {"nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM"};

	s = va_arg(R, char*);

	if (s == NULL)
		s = "(null)";

	for (i = 0; s[i]; i++)
	{
		flag = 0;
		for (j = 0; P[j] && !flag; j++)
		{
			if (s[i] == P[j])
			{
				_putchar(Q[j]);
				count++;
				flag = 1;
			}
		}
		if (!flag)
		{
			_putchar(s[i]);
			count++;
		}
	}
	return (count);
}

