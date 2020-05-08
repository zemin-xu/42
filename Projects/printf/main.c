#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    int a = ft_printf("$%0*d$\n",-4, 0);
    int b = printf("$%0*d$\n",-4, 0);
    printf("%d  || %d", a, b);
}