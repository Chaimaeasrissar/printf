#include "main.h"

/**
 * _printf - Print everything
 * @format: format is a character string
 * Return: the number of characters printed
*/
int _printf(const char *format, ...)
{
	int sum = 0;
	va_list org_list;
	char *start, *p;
	int flags, width, precision, modifier, specifier, func_ind = 0;

	functions = func;
	va_start(org_list, format);

	if (!format || (format[0] == '%' && format[1] == ' ' && !format[2]))
		return (-1);
	for (p = (char *)format; *p; p++)
	{
		func(&functions, org_list);
		if (*p != '%')
		{
			sum += _putchar(*p);
			continue;
		}
		start = p;
		p++;
		while (get_flag(p, &functions))
			/* while char at p is a flag char */
		{
			p++;
			/* to the next char */
		}
		p = get_width(p, &functions, org_list);
		p = get_precision(p, &functions, org_list);
		if (get_modifier(p, &functions, org_list))
			p++;
		if (!get_specifier(p))
			sum += print_from_to(p, start,
					functions1_modifier || functions2_modifier ? p - 1 : 0);
		else
			sum += get_print_func(p, org_list, &functions);
	}
	_puchtar(BUF_FLUSH);
	va_end(org_list);
	return (sum);
}
