//
// Created by ubuntuser on 21.03.2020.
//

/*
** Suggested algorithm:
** Step 0. Read all given arguments and save it to void** array. Problem: count size of array before allocation
**         Problem: adopt va_arg for int and char simultaneously
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
    void    *narg;
    //char    *first_arg;
    int     i;

    i = 0;
    va_start(argptr, format);
    ft_putendl(va_arg(argptr, void*));
    while((narg = va_arg(argptr, void*)))
    {
        i++;
        ft_putendl((char*)narg);
    }
    va_end(argptr);
    ft_putnbr(i);
    return (0);
}

