#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
    int a = 123;
    unsigned int b = 123456789;
    printf("%p\n", &a);
    ft_printf("Hello, World!\n%s\n%s\n%c\n%d\n%p\n", "I love you!", "~UwU~", 'u', 777, &a);
    ft_printf("%o\n%u\n%x\n%X\n", 123, b, 123, 123);
    printf("%o\n%u\n%x\n%X\n%hd", 123, b, 123, 123, 123456);
    printf("%hhdull\n ohmg", 345);
    //printf("Hello, World!\n%s\n%s", "I love you!", 55);
    return 0;
}
