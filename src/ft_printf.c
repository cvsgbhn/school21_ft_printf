//
// Created by ubuntuser on 21.03.2020.
//

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

int     ft_final_print(const char *fstr/*, va_list arg_list*/)
{
    //char    *position;

    //position = ft_putformat(&fstr);
    ft_putstr((char *)fstr);
    ft_putchar('\n');
    return (1);
}

int    ft_parse_args(t_pf *puts)
{
    char    *position;

    position = (char *)puts->format;
    if(*position == 's')
        ft_handle_string(puts);
    return (1);
}

int     ft_printf(const char *format, ...)
{
    t_pf    *puts;

    puts = (t_pf *)malloc(sizeof(t_pf));
    if(format)
    {
        va_start(puts->args, format);
        puts->format = (char *)format;
        ft_strcpy(puts->copy_format, puts->format);
        if ((ft_parse_args(puts)) == 1)
            ft_final_print(puts->format/*, puts->args*/);
        va_end(puts->args);
    }
    ft_memdel((void **)puts);
    return (0);
}
