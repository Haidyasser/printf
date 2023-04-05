#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <string.h>
/**
 * print_char - prints a char
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c;
	c = (char)va_arg(args, int);
	return (write(1, &c, 1));
}
/**
 * print_string - prints a string
 * @args: va_list of arguments
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int len;

	str = va_arg(args, char *);
	if (!str)
		return -1;
	len = strlen(str);
	return (write(1, str, len));
}
/**
 * _printf - produces output according to a format
 * @format: character string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, printed = 0;
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				printed = print_char(args);
				break;
			case 's':
				printed = print_string(args);
				break;
			case '%':
				printed = write(1, "%", 1);
				break;
			default:
				printed = -1;
				break;
			}
		}
		else
		{
			printed = write(1, format, 1);
		}
		if (printed <= -1)
		{
			va_end(args);
			return (-1);
		}
		count += printed;
		format++;
	}
	va_end(args);
	return (count);
}
