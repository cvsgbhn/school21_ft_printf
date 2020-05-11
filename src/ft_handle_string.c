#include "../includes/ft_printf.h"


int     ft_handle_string(t_pf *puts)
{
    char    *arg;

    arg = va_arg(puts->args, char*);
    ft_putstr(arg);
    return (0);
}