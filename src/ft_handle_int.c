//
// Created by ubuntuser on 11.05.2020.
//

#include "../includes/ft_printf.h"

int     ft_handle_int(t_pf *puts)
{
    int     i_arg;
    char    *s_arg;

    i_arg = va_arg(puts->args, int);
    s_arg = ft_itoa(i_arg);
    ft_putstr(s_arg);
    return (1);
}