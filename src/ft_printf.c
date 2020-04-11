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

char     *ft_putformat(const char **string)
{
    char    *traverse;

    traverse = (char *)*string;
    while( *traverse != '%' && *traverse)
    {
        ft_putchar(*traverse);
        traverse++;
    }
    return traverse;
}

int    fake_function(va_list arg_list)
{
    arg_list++;
    return (0);
}

int    ft_parse_args(const char *fstr, va_list arg_list)
{
    char    *position;

    position = ft_putformat(&fstr);
    while(*position != '\0')
    {
        position++;
        //handle format conversion
        if(*position == 's')
            ft_putstr(va_arg(arg_list, char *));
        else if(*position == 'c')
            ft_putchar(va_arg(arg_list, int));
        else if(*position == 'p') // ATTENTION! %p should handle pointer of ANY type
            ft_putstr((char *)va_arg(arg_list, void *));
        else if(*position == 'd')
            ft_putstr(ft_itoa(va_arg(arg_list, int)));
        else
            position = ft_putformat((const char **)&position);
    }
    fake_function(arg_list);
    return (1);
}

int     ft_printf(const char *format, ...)
{
    //char *position;
    va_list argptr;

    va_start(argptr, format);
    ft_parse_args(format, argptr);
    return (0);
}
