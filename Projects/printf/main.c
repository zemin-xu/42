#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a = ft_printf("$%c$\n", 1);
    int b = printf("$%c$\n", 1);

    printf("%d  || %d", a, b);
}