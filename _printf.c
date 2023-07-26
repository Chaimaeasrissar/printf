#include "main.h"

/**
 * _printf - Produces output according to a format.
 * @format: The format string.
 *
 * Return: The number of characters printed (excluding the null byte used
 * to end output to strings).
*/
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;
	int printed_chars = 0;

	va_start(args, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '%')
			{
				write(1, &format[i], 1);
				printed_chars++;
			}
			else if (format[i] == 'c')
			{
				char c = va_arg(args, int);

				write(1, &c, 1);
				printed_chars++;
			}
			else if (format[i] == 's')
			{
				char *str = va_arg(args, char*);
				int j = 0;
			}
			else
			{
				write(1, &format[i - 1], &format[i], 1);
				printed_chars += 2;
				printed_chars++;
			}
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}
