#include "main.h"

/**
 * handle_precision - Extracts the precision from the format string.
 * @format: The format string.
 * @index: The current position in the format string.
 * @precision: A pointer to store the extracted precision value.
 *
 * Return: The new index after handling the precision.
 */
int handle_precision(const char *format, int index, int *precision)
{
	if (format[index] == '.')
	{
		int i = index + 1;
		*precision = 0;

		while (format[i] >= '0' && format[i] <= '9')
		{
			*precision = (*precision * 10) + (format[i] - '0');
			i++;
		}

		return (i);
	}

	return (index);
}
