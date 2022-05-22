#include "main.h"
#include <stdarg.h>
/**
 *function_manager - function manager
 *@c: character to find
 *@arg: va_list type
 *Description: This function call other functions
 * when the character is found
 *Return: count of printed characters
 */
int function_manager(char c, va_list arg)
{
	int cont = 0;

	cont = _switch(c, arg);
	if (c == 'p')
		cont = print_ptr(arg);
	return (cont);
}
/**
 *_switch - switch
 *@c: character to find
 *@arg: va_list type
 *Description: This function evaluate cases
 *Return: count of printed characters
 */
int _printf(const char *format, ...)
{
	int count;
	int total = 0;
	va_list args;
	int flag = 0;

	if (format == NULL)
		return (0);

	va_start(args, format);
	for (count = 0; *(format + count) != '\0'; count++)
	{
		if (format[count] == '%')
		{
			flag = 1;
		}
		else if (flag == 1)
		{
			flag = 0;
			switch (format[count])
			{
				case 'c':
					_putchar(va_arg(args, int));
					total += 1;
					break;
				case 's':
					total += _print_str(va_arg(args, char *));
					break;
				case '%':
					_putchar('%');
					total += 1;
					break;
				case 'd':
					total += _print_int((long)(va_arg(args, int)));
					break;
				case 'i':
					total += _print_int((long)(va_arg(args, int)));
					break;
				case 'b':
					total += to_Binary(va_arg(args, int));
					break;
				case 'u':
					total += _print_int(va_arg(args, unsigned int));
					break;
				case 'o':
					total += to_Octal(va_arg(args, int));
					break;
				case 'x':
					total += to_Hexa(va_arg(args, int));
					break;
				case 'X':
					total += to_Hexa(va_arg(args, int));
					break;
				default:
					_putchar('%');
					_putchar(format[count]);
					total += 2;
			}
		}
		else
		{
			_putchar(format[count]);
			total += 1;
		}
	}
	va_end(args);
	return (total);
}
