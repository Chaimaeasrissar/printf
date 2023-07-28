#include "main.h"
/**
 * print_binary - Prints an unsigned integer as binary.
 * @num: The unsigned integer to be printed.
 *
 * Return: The number of characters printed.
 */
int print_binary(unsigned int num)
{
	int i = 0;
	int arr[32];
	int j = 0;

	if (num == 0)
	{
		_putchar('0');
		return (1);
	}

	while (num > 0)
	{
		arr[j] = num % 2;
		num /= 2;
		j++;
	}

	for (i = j - 1; i >= 0; i--)
	{
		_putchar(arr[i] + '0');
	}

	return (j);
}
/**
 * print_S - Prints a string with special handling for S
 * @str: The string to be printed.
 *
 * Return: The number of characters printed (excluding the null byte).
 */
int print_S(const char *str)
{
	int i = 0, count = 0;

	if (str == NULL)
	{
		return (print_S("(null)"));
	}
	while (str[i])
	{
		if (str[i] >= 32 && str[i] < 127)
		{
			_putchar(str[i]);
			count++;
		}
		else
		{
			_putchar('\\');
			_putchar('x');
			if (str[i] < 16)
				_putchar('0');
			count += 3;
			count += print_hexa(str[i], 1);
		}
		i++;
	}

	return (count);
}
