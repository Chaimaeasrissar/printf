#include "main.h"

/**
 * get_width - the Calculates width for print
 * @format: Formatted string to print the arguments.
 * @cr: List of arguments to be Printed.
 * @list_a: list of arguments.
 *
 * Return: width.
*/

int get_width(const char *format, int *cr, va_list list_a)
{
	int curr_c;
	int width = 0;

	for (curr_c = *cr + 1; format[curr_c] != '\0'; curr_c++)
	{
		if (is_digit(format[curr_c]))
		{
			width *= 10;
			width += format[curr_c] - '0';
		}
		else if (format[curr_c] == '*')
		{
			curr_c++;
			width = va_arg(list_a, int);
			break;
		}
		else
			break;
	}
	*cr = curr_c - 1;

	return (width);
}
