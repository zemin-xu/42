#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int a =5;
	int i;
	int j;

	i = printf("$%20p$\n", &a);
	j = ft_printf("$%20p$\n",&a);
	
	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}