#include <stdio.h>
#include "main.h"

/**
 * main - main function of program
 * Return: always 0
 */

int main(void)
{
        int num;
        char *string;

        num = 98;
        string = "%%%";

        _printf("%s is %i.\n", string, num);
	printf("%s is %i.\n", string, num);

        return (0);
}
