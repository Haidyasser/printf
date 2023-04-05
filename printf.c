#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * print_char - Prints a character
 * @args: List of arguments
 * @count: Pointer to the character count
 */
void print_char(va_list args, int *count)
{
	char c = va_arg(args, int);

	write(1, &c, 1);
	(*count)++;
}

/**
 * print_string - Prints a string
 * @args: List of arguments
 * @count: Pointer to the character count
 */
void print_string(va_list args, int *count)
{
	int j;
	char *s = va_arg(args, char *);

	for (j = 0; s[j] != '\0'; j++)
	{
		write(1, &s[j], 1);
		(*count)++;
	}
}

/**
 * print_percent - Prints a percent sign
 * @count: Pointer to the character count
 */
void print_percent(int *count)
{
	char c = '%';

	write(1, &c, 1);
	(*count)++;
}

/**
 * _printf - Produces output according to a format
 * @format: Character string composed of zero or more directives
 *
 * Return: The number of characters printed (excluding the null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;

	va_start(args, format);
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					print_char(args, &count);
					break;
				case 's':
					print_string(args, &count);
					break;
				case '%':
					print_percent(&count);
					break;
			}
		}
		else
		{
			write(1, &format[i], 1);
			count++;
		}
	}
	va_end(args);
	return (count);
}

