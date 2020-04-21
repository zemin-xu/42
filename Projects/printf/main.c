#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;
	i = printf("$%7.9s$\n", "wherehello");
	j = ft_printf("$%7.9s$\n", "wherehello");

	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}