#include "main.h"

/************** PRINT ROT13 *****************/
/**
 * print_rot13 - Prints a rot13'ed version of the input string
 * @args_list: List of arguments
 * @output_buffer: Buffer array to handle print
 * Return: Number of chars printed.
*/
int print_rot13(va_list args_list, char output_buffer[])
{
	char *str = va_arg(args_list, char *);
	char c;
	int i, j;
	char *input = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char *output = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
	int chars_printed = 0;

	for (i = 0; str[i]; i++)
	{
		c = str[i];
		for (j = 0; input[j]; j++)
		{
			if (c == input[j])
			{
				c = output[j];
				break;
			}
		}
		output_buffer[i] = c;
		chars_printed++;
	}
	output_buffer[i] = '\0';

	return (chars_printed);
}
