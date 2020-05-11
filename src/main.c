#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
    ft_printf("Hello, World!\n%s\n%s\n%c\n%d\n", "I love you!", "~UwU~", 'u', 777);
    //printf("Hello, World!\n%s\n%s", "I love you!", 55);
    return 0;
}
