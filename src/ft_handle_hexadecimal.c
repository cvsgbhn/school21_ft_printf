//
// Created by ubuntuser on 21.06.2020.
//

#include "../includes/ft_printf.h"

int     ft_handle_hexadecimal(t_pf *puts, char c)
{
    uintmax_t    i_arg;
    char    *s_arg;

    i_arg = va_arg(puts->args, int);
    if (c == 'p' || c == 'x')
        s_arg = ft_itoa_base(i_arg, 16, 'x');
    else
        s_arg = ft_itoa_base(i_arg, 16, 'X');
    ft_putstr(s_arg);
    return (1);
}

int     ft_handle_octal(t_pf *puts)
{
    int     i_arg;
    char    *s_arg;

    i_arg = va_arg(puts->args, int);
    s_arg = ft_itoa_base(i_arg, 8, 'x');
    ft_putstr(s_arg);
    return (1);
}