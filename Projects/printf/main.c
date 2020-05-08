#include "ft_printf.h"
#include <stdio.h>

int main(void)
{
    ft_printf("$%-4c$\n", 0);
    ft_printf("$%-4c$\n", 1);
    ft_printf("$%-4c$\n", 49);
    ft_printf("$%c$\n", 49);
    ft_printf("$%4.9d$\n", 12);
    ft_printf("$%*.*d$\n", -4, -8, 12);
}