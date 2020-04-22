#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;

	i = printf("$%u$\n",  'c');
	j = ft_printf("$%u$\n", 'c');
	
	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}