#include "../includes/ft_printf.h"

int     ft_rewrite_format(t_pf *puts, char *arg)
{
   // ft_putendl("ft_handle_string.c ft_rewrite_format");
    char    *traverse;
    char    *next_start;
    int     i;
    size_t  new_size;

    new_size = ft_strlen(puts->copy_format) + ft_strlen(arg);
    //ft_putendl("1 ft_handle_string.c ft_rewrite_format");
    puts->copy_format = ft_memalloc(new_size);
    //ft_putendl("3 ft_handle_string.c ft_rewrite_format");
    traverse = puts->format;
    //ft_putendl("4 ft_handle_string.c ft_rewrite_format");
    i = 0;
    while (*traverse != '%' && *traverse)
    {
     //   ft_putendl("5 ft_handle_string.c ft_rewrite_format");
        i++;
        traverse++;
    }
    ft_strncpy(puts->copy_format, puts->format, i);
  //  ft_putendl("6 ft_handle_string.c ft_rewrite_format");
    next_start = puts->copy_format;
    while (*next_start != '\0')
        next_start++;
    //ft_putendl("7 ft_handle_string.c ft_rewrite_format");
    ft_strcpy(next_start, arg);
    while (*arg)
    {
      //  ft_putendl("8 ft_handle_string.c ft_rewrite_format");
        next_start++;
        arg++;
    }
    traverse++;
    ft_strcpy(next_start, traverse);
    //ft_putendl("9 ft_handle_string.c ft_rewrite_format");
    ft_putstr(puts->copy_format);
    return (1);
}

int     ft_error()
{
   // ft_putendl("ft_printf.c ft_error");
    ft_putstr("ERROR");
    return (0);
}

int     ft_handle_string(t_pf *puts)
{
   // ft_putendl("ft_printf.c ft_error");
    char    *arg;

    arg = va_arg(puts->args, char*);
    ft_rewrite_format(puts, arg);
    return (0);
}