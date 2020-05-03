#include "../includes/ft_printf.h"

int     ft_rewrite_format(t_pf *puts, char *arg)
{
    char    *traverse;
    char    *next_start;
    int     i;
    size_t  new_size;

    new_size = ft_strlen(puts->copy_format) + ft_strlen(arg);
    ft_memdel((void **)puts->copy_format);
    puts->copy_format = ft_memalloc(new_size);
    ft_bzero(arg, ft_strlen(arg));
    traverse = puts->format;
    i = 0;
    while (*traverse != '%' && *traverse)
    {
        i++;
        traverse++;
    }
    ft_strncpy(puts->copy_format, puts->format, i);
    next_start = puts->copy_format;
    while (*next_start != '\0')
        next_start++;
    ft_strcpy(next_start, arg);
    while (*arg)
    {
        next_start++;
        arg++;
    }
    traverse++;
    ft_strcpy(next_start, traverse);
    ft_putstr(puts->copy_format);
    return (1);
}

int     ft_error()
{
    ft_putstr("ERROR");
    return (0);
}

int     ft_handle_string(t_pf *puts)
{
    char    *arg;
    char    *p;

    arg = va_arg(puts->args, char*);
    p = arg;
    while (p)
    {
        if (ft_isprint(*p) == 1)
            p++;
        else
        {
            ft_error();
            return (-1);
        }
    }
    ft_rewrite_format(puts, arg);
    return (0);
}