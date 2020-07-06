//
// Created by ubuntuser on 21.03.2020.
//

#include "../includes/ft_printf.h"

int     ft_handle_format(t_pf *puts)
{
    char c;

    c = *(puts->p_format);
    if (c == 's')
        ft_handle_string(puts);
    if (c == 'c')
        ft_handle_char(puts);
    if (c == 'd' || c == 'i')
        ft_handle_int(puts);
    if (c == 'p' || c == 'x' || c == 'X')
        ft_handle_hexadecimal(puts, c);
    if (c == 'o')
        ft_handle_octal(puts);
    if (c == 'u')
        ft_handle_u(puts);
    else
        return (0);
    return (1);
}

int     is_format(char c)
{
    if (c == 's' || c == 'c' || c == 'd' || c == 'p'
        || c == 'i' || c == 'o' || c == 'u' || c == 'x' || c == 'X')
        return (1);
    else
        return (0);
}

int    ft_parse_args(t_pf *puts)
{
    if (is_format(*puts->p_format))
        ft_handle_format(puts);
    return (1);
}

int     formatparse(const char *format, t_struct *list, va_list ap, int pos)
{
    while (format[pos] != '%' && format[pos])
    {

    }
}

int     ft_putformat(t_pf *puts)
{
    char    *cur;
    int     i;

    cur = (char *)(puts->format);
    i = 0;
    while( cur[i] != '\0')
    {
        if(cur[i] == '%')
        {
            puts->p_format= &(cur[++i]);
            ft_parse_args(puts);
        }
        else
            ft_putchar(cur[i]);
        i++;
    }
    return (i);
}

int     ft_printf(const char *format, ...)
{
    t_pf    *puts;

    if (!(puts = (t_pf *)malloc(sizeof(t_pf))))
        return (-1);
    if(format)
    {
        va_start(puts->args, format);
        puts->format = (char *)format;
        puts->copy_format = ft_memalloc(ft_strlen(format));
        ft_putformat(puts);
        va_end(puts->args);
    }
    free(puts);
    return (0);
}
