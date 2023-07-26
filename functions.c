#include "main.h"

/**
 * custom_printf - Custom implementation of printf that handles 'd' and 'i'
 * @format: The format string
 * @...: Variable number of arguments to be printed according to the format.
 *
 * Return: The total number of characters printed.
*/
int custom_printf(const char *format, ...)
{
	va_list args_list;

	va_start(args_list, format);
	chars_printed = 0;
	char buffer[100];

	while (*format != '\0')
	{
		if (*format == '%')
		{
			if (*format == 'd' || *format == 'i')
			{
				int num = va_arg(args_list, int);
				int i = 0;

				if (num == 0)
				{
					buffer[i++] = '0';
				}
				if (num < 0)
				{
					buffer[i++] = '-';
					num *= -1;
				}
				while (num > 0)
				{
					buffer[i++] = (num % 10) + '0';
					num /= 10;
				}
			}
			while (int j = i - 1; j >= 0)
			{
				_std_gnu99(buffer[j], '%', *format);
				chars_printed++;
			}
		}
		format++;
	}
	va_end(args_list);
	return (chars_printed);
}
