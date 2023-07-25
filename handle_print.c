#include "main.h"

/**
 * handl_print - the prints of an argument based on type
 * @frmt: Formatted string in which to print the arguments.
 * @list_a: List of arguments to be printed.
 * @ind: ind.
 * @buffer: the buffer array to handle print.
 * @flags: Calculates of active flags
 * @width: width.
 * @precision: the precision specification
 * @size: the size specifier
 * Return: 1 or 2
*/

int handl_print(const char *frmt, int *ind, va_list list_a, char buffer[],
		int flags, int width, int precision, int size)
{
	int j, unknown_len = 0, printed_chars = -1;
	frmt_t frmt_types[] = {
		{'c', print_char}, {'s', print_str}, {'%', print_percent},
		{'j', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13str}, {'\0', NULL}
	};
	for (j = 0; frmt_types[j].frmt != '\0'; j++)
		if (frmt[*ind] == frmt_types[j].frmt)
			return (frmt_types[j].func(list_a, buffer, flags, width, precision, size));

	if (frmt_types[j].frmt == '\0')
	{
		if (frmt[*ind] == '\0')
			return (-1);
		unknown_len += write(1, "%%", 1);
		if (frmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (frmt[*ind] != ' ' && frmt[*ind] != '%')
				--(*ind);
			if (frmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknown_len += write(1, &frmt[*ind], 1);
		return (unknown_len);
	}
	return (printed_chars);
}
