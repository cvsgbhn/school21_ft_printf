//
// Created by ubuntuser on 21.03.2020.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>
#include "../libft/libft.h"

// to delete
#include <stdio.h>

#define ALLFLAGS "cspdiouxXfy%#-+ .*0123456789hLljz"

typedef struct  s_printf
{
    char    *format;
    char    *p_format;
    int     nprinted;
    int     i;
    int     len;
    int     minus;
    int     plus;
    int     space;
    int     zero;
    int     hash;

    int     width;
    int     precisionf;
    int     precision;
    int     length;
    va_list args;
}               t_pf;

int     ft_handle_string(t_pf *puts);
int     ft_handle_char(t_pf *puts);
int     ft_handle_int(t_pf *puts);
int     ft_handle_hexadecimal(t_pf *puts, char c);
int     ft_handle_octal(t_pf *puts);
int     ft_handle_u(t_pf *puts);
char    *ft_itoa_base(uintmax_t num, int base, int letter);
int     ft_printf(const char *format, ...);

#endif
