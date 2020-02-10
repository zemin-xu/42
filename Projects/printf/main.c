#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;
	i = printf("$%-10.5d$\n", -847);
	j = ft_printf("$%-10.5d$\n", -847);
	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}