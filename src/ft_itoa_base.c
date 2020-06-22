//
// Created by ubuntuser on 31.05.2020.
//

#include "../includes/ft_printf.h"

static int  to_char(int remainder, int letter)
{
    if (remainder>=0 && remainder<=9)
        return (remainder + '0');
    if (remainder>=10 && remainder<=16)
    {
        if (letter == 'X')
            return (remainder + 'A' - 10);
        else
            return (remainder + 'a' - 10);
    }
    return (0);
}

static int  count(uintmax_t num, int base)
{
    int     count;

    count = 0;
    while (num > 0)
    {
        num /= base;
        count++;
    }
    return (count);
}

char     *ft_itoa_base(uintmax_t num, int base, int letter)
{
    int     length;
    char    *string;

    length = count(num, base);
    if (! (string = ft_strnew(length)))
        return (string);
    string[length] = '\0';
    while (num > 0)
    {
        length--;
        string[length] = to_char(num % base, letter);
        num /= base;
    }
    return (string);
}