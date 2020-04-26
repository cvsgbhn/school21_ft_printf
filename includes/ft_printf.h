//
// Created by ubuntuser on 21.03.2020.
//

#ifndef FT_PRINTF_FT_PRINTF_H
#define FT_PRINTF_FT_PRINTF_H

#include <stdarg.h>
#include <unistd.h>
#include "../libft/libft.h"

// to delete
#include "stdio.h"

typedef struct  s_printf
{
    char    *format;
    char    *copy_format;
    char    *p_format;
    va_list args;
}               t_pf;

int     ft_printf(const char *format, ...);
int     ft_handle_string(t_pf *puts);

#endif //FT_PRINTF_FT_PRINTF_H
