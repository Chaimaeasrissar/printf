#include "main.h"

/************** PRINT PLUS FLAG *****************/
/**
 * print_plus_flag - Prints a plus flag for signed integers
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_plus_flag(va_list args_list, char output_buffer[])
{
	int num = va_arg(args_list, int);
	int i = BUFF_SIZE - 2;

	if (num >= 0)

		output_buffer[i--] = '+';

	return (print_signed int(args_list, output_buffer + i + 1) + 1);
}

/************** PRINT SPACE FLAG *****************/
/**
 * print_space_flag - Prints a space flag for signed integers
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_space_flag(va_list args_list, char output_buffer[])
{
	int num = va_arg(args_list, int);
	int i = BUFF_SIZE - 2;

	if (num >= 0)
		output_buffer[i--] = ' ';

	return (print_signed int(args_list, output_buffer + i + 1) + 1);
}
/************** PRINT HASH FLAG *****************/
/**
 * print_hash_flag - Prints a hash flag for various conversions
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_hash_flag(va_list args_list, char output_buffer[])
{
	int chars_printed = 0;
	int i = BUFF_SIZE - 2;
	char specifier = va_arg(args_list, int);

	if (specifier == 'o')
	{
		output_buffer[i--] = '0';
		chars_printed = print_octal(args_list, output_buffer + i + 1);
	}
	else if (specifier == 'x' || specifier == 'X')
	{
		output_buffer[i--] = (specifier == 'x') ? 'x' : 'X';
		output_buffer[i--] = '0';
		chars_printed = print_hexadecimal(args_list, output_buffer + i + 1);
	}
	else if (specifier == 'b')
	{
		output_buffer[i--] = 'b';
		output_buffer[i--] = '0';
		chars_printed = print_binary(args_list, output_buffer + i + 1);
	}
	else
	{
		output_buffer[i--] = specifier;
		chars_printed = 1;
	}
	return (chars_printed + 2);
}
