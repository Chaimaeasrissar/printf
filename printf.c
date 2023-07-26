#include "main.h"
#include <stdint.h>

/*
 * _printf: printf
 * p_precent: print precent
 * p_integer: print integer
 * p_string: print string
 * print_number: print number
 *
 * Return: void.
*/

#define UNUSED(x) (void)(x)

int _printf(const char *format, ...)
{
	int printed_chars;

	conver_t funct_list[] = {
		{"c", p_char},
		{"s", p_string},
		{"%", p_percent},
		{"d", p_integer},
		{"i", p_integer},
		{NULL, NULL}
	};

	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	/* call a parser function*/

	printed_chars = parser(format, funct_list, args);
	va_end(args);

	return (printed_chars);
}

/*p_precent*/
int p_percent(va_list args)
{
	UNUSED(args);
	return (_putchar('%'));
}

/*p_integer*/
int p_integer(va_list args)
{
	int n = va_arg(args, int);
	int res = 0;

	if (n < 0)
	{
		res += _putchar('-');
		n = -n;
	}

	res += print_number(args, 10, "0123456789");

	return (res);
}
