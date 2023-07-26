#include "main.h"

/**
 * is_printable - the evaluates if a char is printable
 * @cr: Char to be Evaluated.
 *
 * Return: 1 if cr is printable, 0 otherwise.
*/

int is_printable(char cr)
{
	if (cr >= 32 && cr < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code to buffer
 * @buffer: Array of chars.
 * @j: Index at which to start appending.
 * @asci_code: ASSCI CODE.
 * Return: Always 3
*/

int append_hexa_code(char asci_code, char buffer[], int j)
{
	char map_to[] = "0123456789ABCDEF";
	/* the hexa format code is always 2 digits long */
	if (asci_code < 0)
		asci_code *= -1;

	buffer[j++] = '\\';
	buffer[j++] = 'x';

	buffer[j++] = map_to[asci_code / 16];
	buffer[j] = map_to[asci_code % 16];


a	return (3);
}

/**
 * is_digit - the verifies if a char is a digit
 * @cr: Char to be evaluated
 *
 * Return: 1 if cr is a digit, 0 otherwise
*/

int is_digit(char cr)
{
	if (cr >= '0' && cr <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - the casts a number to the specified size
 * @num: Number to be casted.
 * @size: Number indicating the type to be casted.
 *
 * Return: Casted value of num
*/

long int convert_size_number(long int num, int size)
{
	if (size == SI_LONG)
		return (num);
	else if (size == SI_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - the casts a number to the specified size
 * @num: Number to be casted
 * @size: Number indicating the type to be casted
 *
 *
 * Return: Casted value of num
*/

long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == SI_LONG)
		return (num);
	else if (size == SI_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
