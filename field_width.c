#include "file.h"

/**
 * get_width - gets the width from the format string
 * @str: the format string
 * @func: the parameters struct
 * @list: the argument pointer
 *
 * Return: new pointer
 */
char *get_width(char *str, param_func *func, va_list list)
{
	int i = 0;

	if (*str == '*')
	{
		i = va_arg(list, int);
		i++;
	}
	else
	{
		while (is_digit(*str))
			i = i * 10 + (*str++ - '0');
	}
	func->width = i;
	return (str);
}

