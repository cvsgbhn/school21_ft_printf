//
// Created by ubuntuser on 21.03.2020.
//

#include "../includes/ft_printf.h"

char     *ft_putformat(const char **string)
{
    //ft_putendl("ft_printf.c ft_putformat");
    char    *traverse;

    traverse = (char *)*string;
    while( *traverse != '%' && *traverse)
    {
        //ft_putchar(*traverse);
        traverse++;
    }
    return traverse;
}

int     ft_final_print(const char *fstr/*, va_list arg_list*/)
{
    //ft_putendl("ft_printf.c ft_final_print");
    ft_putstr((char *)fstr);
    ft_putchar('\n');
    return (1);
}

int    ft_parse_args(t_pf *puts)
{
   // ft_putendl("ft_printf.c ft_parse_args");
    char    *position;

    position = ft_putformat((const char **)&(puts->format));
    while (*position != '\0')
    {
        position++;
        if (*position == 's')
            ft_handle_string(puts);
    }
    return (1);
}

int     ft_printf(const char *format, ...)
{
    //ft_putendl("ft_printf.c ft_printf");
    t_pf    *puts;

    if (!(puts = (t_pf *)malloc(sizeof(t_pf))))
        return (-1);
   // ft_putendl("1 ft_printf.c ft_printf");
    if(format)
    {
     //   ft_putendl("2 ft_printf.c ft_printf");
        va_start(puts->args, format);
       // ft_putendl("2.1 ft_printf.c ft_printf");
        puts->format = (char *)format;
        //ft_putendl("2.2 ft_printf.c ft_printf");
        puts->copy_format = ft_memalloc(ft_strlen(format));
        ft_strcpy(puts->copy_format, puts->format);
       // ft_putendl("3 ft_printf.c ft_printf");
        if ((ft_parse_args(puts)) == 1)
            ft_final_print(puts->format/*, puts->args*/);
        //ft_putendl("4 ft_printf.c ft_printf");
        va_end(puts->args);
        //ft_putendl("4.1 ft_printf.c ft_printf");
    }
    free(puts);
    //ft_putendl("5 ft_printf.c ft_printf");
    return (0);
}
