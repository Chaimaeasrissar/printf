#include "main.h"

/*
 * print_number: numbers printed.
 * print_unsgined_number: print.
 * p_char: print char
 * p_string: print string
 * p_precent: print precent
 * P_integer: print integer
 *
 * Return: void
*/

int print_number(va_list args)
{
	int n;
	int check;
	int len;
	unsigned int num;

	n  = va_arg(args, int);
	check = 1;
	len = 0;

	if (n < 0)
	{
		len += _putchar('-');
		num = n * -1;
	}
	else
		num = n;

	for (; num / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}

	return (len);
}

int print_unsgined_number(unsigned int n)
{
	int check;
	int len;
	unsigned int num;

	check = 1;
	len = 0;

	num = n;

	for (; num / check > 9; )
		check *= 10;

	for (; check != 0; )
	{
		len += _putchar('0' + num / check);
		num %= check;
		check /= 10;
	}

	return (len);
}

int p_char(va_list args)
{
	char value;

	value = va_arg(args, int);
	_putchar(value);
	return (1);
}

int p_string(va_list args)
{
	int i;
	const char *s;

	s = va_arg(args, const char *);
	if (s == NULL)
		s = "(null)";
	for (i = 0; s[i] != '\0'; i++)
		_putchar(s[i]);
	return (i);
}

int p_percent_integer(__attribute__((unused)) va_list args)
{
	int n; /* for integer */

	n = print_number(args);
	return (n);

	/* for percent */
	_putchar('%');
	return (1);
}
