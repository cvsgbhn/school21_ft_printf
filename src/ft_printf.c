//
// Created by ubuntuser on 21.03.2020.
//

/*
** Suggested algorithm:
** Step 0. Read all given arguments and save it to void** array.
** Step 1. Analyze all given arguments:
** Step 1.1. Analyze format string
** Step 1.2. While analyzing format string, if "%" - call function to detect what flag is this exactly
** Step 1.3. Rewrite format string: before flag part + argument + after flag part
** Step 2. Print result format string
*/

#include "../includes/ft_printf.h"

int     ft_printf(const char *format, ...)
{
    va_list argptr;
    int     i;

    i = 0;
    va_start(argptr, format);
    while(va_arg(argptr, void*))
        i++;
    va_end(argptr);
    ft_putnbr(i);
    return (0);
}

