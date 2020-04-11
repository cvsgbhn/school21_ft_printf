#include "../includes/ft_printf.h"
#include <stdio.h>

int main()
{
    void *experiment = "Science, bitch!!!";
    ft_printf("%c\nHello, World!\n%s\n%c\n%p\n%d\n", 'A', "I love you!", 'F', experiment, 666);
    //ft_printf("Hello\n", 1, 2, 3, 4, 5, 6, 7, 8, 9, 10);
    //ft_printf("Bye\n", 'a', 'b', 'c', "fgweth");
    return 0;
}
