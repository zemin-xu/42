#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;

	i = printf("$%07.5d$\n",  -17);
	j = ft_printf("$%07.5d$\n", -17);

	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}