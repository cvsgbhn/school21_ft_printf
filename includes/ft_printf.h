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
    va_list args;
}               t_pf;

int     ft_printf(const char *format, ...);

#endif //FT_PRINTF_FT_PRINTF_H
