#include <unistd.h>
#include <string.h>

/**
 * _print_char - Print a single character c
 * @c: pointer to character
 *
 * Return: integer return 0 if c is NULL else 1
 */

int _print_char(const char *c)
{
	if (c == NULL)
		return (0);
	write(0, c, 1);
	return (1);
}

/**
 * _print_str - Print a string pointed to by str
 * @str: pointer to string
 *
 * Return: integer return 0 if str is NULL else size of str
 */

int _print_str(const char *str)
{
	int size;

	if (str == NULL)
		return (0);
	size = strlen(str);
	write(0, str, size);
	return (size);
}
