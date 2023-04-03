#include "main.h"

/**
 * print_int - Prints an integer
 * @args: A va_list of arguments
 *
 * Return: The number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	char buffer[11];
	int i = 0;
	int printed = 0;

	if (n == 0)
	{
		printed = write(1, "0", 1);
		return (printed);
	}

	if (n < 0)
	{
		printed += write(1, "-", 1);
		n = -n;
	}

	while (n > 0)
	{
		buffer[i] = (n % 10) + '0';
		n /= 10;
		i++;
	}

	while (i > 0)
	{
		i--;
		printed += write(1, &buffer[i], 1);
	}

	return (printed);
}
