#include "main.h"

void print_buffer(char buffer[], int *buff_ind);
/**
 *  print_buffer - Prints the contents of the buffer if it exist
 *  @buffer: Array of chars
 *  @buff_ind: Index at which to add next char
*/
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);
	*buff_ind = 0;
}
/**
 * _printf - Printf function
 * @format: formatted string
 * Return: Printed chars
*/
int _printf(const char *format, ...)
{
	int i, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);

	while (i = 0; format && format[i] != '\0')
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			printed_chars++;
			/* write(1, &format[i], 1);*/
		}
		else
		{
			width = get_width(format, &i, list);
			size = get_size(format, &i);
			flags = get_flags(format, &i);
			print_buffer(buffer, &buff_ind);
			precision = get_precision(format, &i, list);
			printed = handle_print(format, &i, list, buffer,
					flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	printed_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}
