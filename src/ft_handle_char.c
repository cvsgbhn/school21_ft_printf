//
// Created by ubuntuser on 11.05.2020.
//

#include "../includes/ft_printf.h"

int     ft_handle_char(t_pf *puts)
{
    char    arg;

    arg = va_arg(puts->args, int);
    ft_putchar(arg);
    return (1);
}