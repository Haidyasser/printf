#include <stdarg.h>
#include <unistd.h>

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
	write(1, &c, 1);
	return (1);
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
	int count = 0;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
			case 'c':
				count += print_char(args);
				break;
			case 's':
				count += print_string(args);
				break;
			case '%':
				write(1, "%", 1);
				count++;
				break;
			default:
				break;
			}
		}
		else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}
