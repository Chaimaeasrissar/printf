#include "main.h"

/**
 * get_flags - the Calculates of active flags
 * @format: Formatted string to print the arguments
 * @cr: take parameter.
 * Return: Flags:
*/

int get_flags(const char *format, int *cr)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int j, curr_c;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {FL_MINUS, FL_PLUS, FL_ZERO, FL_HASH, FL_SPACE, 0};

	for (curr_c = *cr + 1; format[curr_c] != '\0'; curr_c++)
	{
		for (j = 0; FLAGS_CH[j] != '\0'; j++)
			if (format[curr_c] == FLAGS_CH[j])
			{
				flags |= FLAGS_ARR[j];
				break;
			}
		if (FLAGS_CH[j] == 0)
			break;
	}

	*cr = curr_c - 1;

	return (flags);
}
