#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;
	i = printf("$%-10.5d$\n", -847);
	j = ft_printf("$%s$\n", "where");
	ft_printf("%c\n",'a');
	ft_printf("%i\n",134);
	ft_printf("%p\n", &i);
	ft_printf("%x\n", i);
	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}