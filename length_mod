#include "main.h"

/**
 * length_mod - handles the length modifier
 * @str: the format string
 * @func: the parameters struct
 *
 * Return: if modifier was valid
 */
int length_mod(char *str, param_func *func)
{
        int i = 0;

        switch (*str)
        {
                case 'h':
                        i = func->h_mod = 1;
                        break;
                case 'l':
                        i = func->l_mod = 1;
                        break;
        }
        return (i);
}
