#include "ft_printf.h"
#include <stdio.h>

int main()
{
	int i = 1031247822;
	unsigned int j = -12103;
	char *s = "WHEREAREYOU";

	ft_printf("$%.6d$\n", i);
	ft_printf("$%4.6d$\n", i);
	ft_printf("$%8.6d$\n", i);
	ft_printf("$%5d$\n", i);
	ft_printf("$---minus-------$\n");

	ft_printf("$%-.6d$\n", i);
	ft_printf("$%-4.6d$\n", i);
	ft_printf("$%-7.6d$\n", i);
	ft_printf("$%-5d$\n", i);
	ft_printf("$---text-------$\n");
	ft_printf("$%5s$\n", s);
	ft_printf("$%4.5s$\n", s);
	ft_printf("$---unsigned int-------$\n");

	ft_printf("$%.6u$\n", j);
	ft_printf("$%4.6u$\n", j);
	ft_printf("$%7.6u$\n", j);
	ft_printf("$%5u$\n", j);
	ft_printf("$---minus-------$\n");

	ft_printf("$%-.6u$\n", j);
	ft_printf("$%-*.*u$\n",4,6, j);
	ft_printf("$%-*.*u$\n",7,6, j);
	ft_printf("$%-5u$\n", j);
	
	printf("$----------$\n");
	printf("$%.6d$\n", i);
	printf("$%4.6d$\n", i);
	printf("$%8.6d$\n", i);
	printf("$%5d$\n", i);
	printf("$---minus-------$\n");

	printf("$%-.6d$\n", i);
	printf("$%-4.6d$\n", i);
	printf("$%-7.6d$\n", i);
	printf("$%-5d$\n", i);
	printf("$---text-------$\n");
	printf("$%5s$\n", s);
	printf("$%4.5s$\n", s);

	printf("$---unsigned int-------$\n");

	printf("$%.6u$\n", j);
	printf("$%4.6u$\n", j);
	printf("$%7.6u$\n", j);
	printf("$%5u$\n", j);
	printf("$---minus-------$\n");

	printf("$%-.6u$\n", j);
	printf("$%-*.*u$\n",4,6, j);
	printf("$%-*.*u$\n",7,6, j);
	printf("$%-5u$\n", j);

	/*
	int a = 1023523212;

	ft_printf("$%-10.12x$\n", a);
	ft_printf("$%-12.10x$\n", a);
	printf("$----------$\n");
	printf("$%-10.12x$\n", a);
	printf("$%-12.10x$\n", a);
	*/

	
	return 0;
}