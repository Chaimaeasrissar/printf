#include "main.h"
#include <stdio.h>
#include <stdarg.h>

int print_integer(va_list args, char length_modifier)
{
	if (length_modifier == 'l')
	{
		long int n = va_arg(args, long int);

		printf("%ld", n);
	} else if (length_modifier == 'h')
	{
		short int n = va_arg(args, int);

		printf("%hd", n);
	} else
	{
		int n = va_arg(args, int);

		printf("%d", n);
	}
	return (0);
}

int print_unsigned_integer(va_list args, char length_modifier)
{
	if (length_modifier == 'l')
	{
		unsigned long int n = va_arg(args, unsigned long int);

		printf("%lu", n);
	} else if (length_modifier == 'h')
	{
		unsigned short int n = va_arg(args, unsigned int);

		printf("%hu", n);
	} else
	{
		unsigned int n = va_arg(args, unsigned int);

		printf("%u", n);
	}
	return (0);
}

int print_octal(va_list args, char length_modifier)
{
	if (length_modifier == 'l')
	{
		unsigned long int n = va_arg(args, unsigned long int);

		printf("%lo", n);
	} else if (length_modifier == 'h')
	{
		unsigned short int n = va_arg(args, unsigned int);

		printf("%ho", n);
	} else
	{
		unsigned int n = va_arg(args, unsigned int);

		printf("%o", n);
	}
	return (0);
}

int print_hexadecimal(va_list args, char length_modifier, int uppercase)
{
	if (length_modifier == 'l')
	{
		unsigned long int n = va_arg(args, unsigned long int);

		if (uppercase)
		{
			printf("%lX", n);
		} else
		{
			printf("%lx", n);
		}
	} else if (length_modifier == 'h')
	{
		unsigned short int n = va_arg(args, unsigned int);

		if (uppercase)
		{
			printf("%hX", n);
		} else
		{
			printf("%hx", n);
		}
	} else
	{
		unsigned int n = va_arg(args, unsigned int);

		if (uppercase)
		{
			printf("%X", n);
		} else
		{
			printf("%x", n);
		}
	}
	return (0);
}
