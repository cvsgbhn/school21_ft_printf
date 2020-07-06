//
// Created by ubuntuser on 22.06.2020.
//

#include "../includes/ft_printf.h"

/*
 * static intmax_t	get_num(t_tab *tab)
{
	intmax_t	num;

	if (tab->specifier_flag == 'D')
		num = (long)(va_arg(tab->args, long int));
	else if (ft_strcmp(tab->argument_flag, "hh") == 0)
		num = (signed char)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->argument_flag, "h") == 0)
		num = (short)(va_arg(tab->args, int));
	else if (ft_strcmp(tab->argument_flag, "ll") == 0)
		num = (long long)(va_arg(tab->args, long long int));
	else if (ft_strcmp(tab->argument_flag, "l") == 0)
		num = (long)(va_arg(tab->args, long int));
	else if (ft_strcmp(tab->argument_flag, "j") == 0)
		num = (intmax_t)(va_arg(tab->args, intmax_t));
	else if (ft_strcmp(tab->argument_flag, "z") == 0)
		num = (size_t)(va_arg(tab->args, size_t));
	else
		num = (int)(va_arg(tab->args, int));
	num = (intmax_t)num;
	return (num);
}
 */

int     ft_handle_u(t_pf *puts)
{
    unsigned int     i_arg;
    char    *s_arg;

    i_arg = va_arg(puts->args, int);
    s_arg = ft_itoa_base(i_arg, 10, 'x');
    ft_putstr(s_arg);
    return (1);
}