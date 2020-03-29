//
// Created by ubuntuser on 21.03.2020.
//

/*
** Suggested algorithm:
** 1. Print format string until '%'
 * 2. find out what character is after '%'
 * 3. handle
*/

#include "../includes/ft_printf.h"

int     ft_handle_csp(char identifier, ...)
{
    // c char
    // s char*
    // p void*
}

int     ft_choose_handler(char strptr)
{
    if (strptr == 'c' || strptr == 's' || strptr == 'p')
        return 1;
    else
        return 0;
}

char     *ft_putformat(const char *string)
{
    char    *traverse;

    traverse = (char *)string;
    while( *traverse != '%' && *traverse)
    {
        ft_putchar(*traverse);
        traverse++;
    }
    return traverse;
}

int     ft_printf(const char *format, ...)
{
    char *position;
    va_list argptr;

    va_start(argptr, format);
    position = ft_putformat(format);
    position++;
    if (*position == 's')
    {
        ft_putstr(va_arg(argptr, char *));
        position++;
    }
    return (0);
}
