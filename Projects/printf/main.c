#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;

	i = printf("");
	j = ft_printf("");
	
	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}