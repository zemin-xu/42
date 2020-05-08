#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a = ft_printf("$%5x$\n", 32245);
    int b = printf("$%5x$\n", 32245);

    printf("%d  || %d", a, b);
}