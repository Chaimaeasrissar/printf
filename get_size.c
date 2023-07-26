#include "main.h"
#include <stdio.h>

/************** PRINT SIGNED NUMBER WITH LENGTH MODIFIER 'l' *****************/
/**
 * print_signed_long - Prints a signed number with length modifier 'l'
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_signed_long(va_list args_list, char output_buffer[])
{
	long int num = va_arg(args_list, long int);
	int i = BUFF_SIZE - 2;
	int is_negative = 0;

	if (num < 0)
	{
		num *= -1;
		is_negative = 1;
	}

	output_buffer[BUFF_SIZE - 1] = '\0';
	do {
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		output_buffer[i--] = '-';
	i++;

	return (write_unsgnd(0, i, output_buffer));
}
/************** PRINT SIGNED NUMBER WITH LENGTH MODIFIER 'h' *****************/
/**
 * print_signed_short - Prints a signed number with length modifier 'h'
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_signed_short(va_list args_list, char output_buffer[])
{
	short int num = va_arg(args_list, int);
	int i = BUFF_SIZE - 2;
	int is_negative = 0;

	if (num < 0)
	{
		num *= -1;
		is_negative = 1;
	}

	output_buffer[BUFF_SIZE - 1] = '\0';
	do {
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		output_buffer[i--] = '-';
	i++;

	return (write_unsgnd(0, i, output_buffer));
}
/********** PRINT UNSIGNED NUMBER WITH LENGTH MODIFIER 'l' *************/
/**
 * print_unsigned_long - Prints an unsigned number with length modifier 'l'
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_unsigned_long(va_list args_list, char output_buffer[])
{
	unsigned long int num = va_arg(args_list, unsigned long int);
	int i = BUFF_SIZE - 2;

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, output_buffer));
}
/************ PRINT UNSIGNED NUMBER WITH LENGTH MODIFIER 'h' *************/
/**
 * print_unsigned_short - Prints an unsigned number with length modifier 'h'
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
 */
int print_unsigned_short(va_list args_list, char output_buffer[])
{
	unsigned short int num = va_arg(args_list, unsigned int);
	int i = BUFF_SIZE - 2;

	if (num == 0)
		output_buffer[i--] = '0';

	output_buffer[BUFF_SIZE - 1] = '\0';
	while (num > 0)
	{
		output_buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, output_buffer));
}
