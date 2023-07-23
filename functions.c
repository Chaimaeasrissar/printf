#include "main.h"

/*
 * int_func - clears struct fields and reset buf
 * @func: functions
 * @org_list: the origin list
 *
 * Return: 0
*/
void int_func(*functions, va_list org_list)
{
	functions->unsign = 0;

	functions->plus_flag = 0;
	functions->space_flag = 0;
	functions->hashtag_flag = 0;
	functions->zero_flag = 0;
	functions->minus_flag = 0;

	functions->width = 0;
	functions->precision = UINT_MAX;

	functions->h_modifier = 0;
	functions->l_modifier = 0;
	(0)org_list;
}
