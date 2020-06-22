#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
    int a = 123;
    printf("%p\n", &a);
    ft_printf("Hello, World!\n%s\n%s\n%c\n%d\n%p\n", "I love you!", "~UwU~", 'u', 777, &a);
    ft_printf("%p\n", &a);
    //printf("Hello, World!\n%s\n%s", "I love you!", 55);
    return 0;
}
