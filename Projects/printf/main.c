#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i;
	int j;

	i = printf("$%c$\n", '\0');
	j = ft_printf("$%c$\n",'\0');
	
	printf("-------------\n");
	printf("ori = %d\n", i); 
	printf("mine = %d\n", j); 
	
	return 0;
}