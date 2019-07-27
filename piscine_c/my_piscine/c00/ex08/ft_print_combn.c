/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 07:21:24 by zexu              #+#    #+#             */
/*   Updated: 2019/06/06 09:25:00 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_combn(int n);
void		recursive(int n, int *index);

int			main(void)
{
	ft_print_combn(4);
	return 0;



}

void		ft_print_combn(int n)
{
	int array[n];
	int i;	

	i=0;
	while (i < n)
	{
		array[n - 1 - i] =  i;
		i++;
	}

	recursive(n, &array[i]);
}
void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		recursive(int n, int *index)
{
	if (n == 1)
	{
		while ((*index) < 10)
		{
			ft_putchar('0' + *index);
			ft_putchar(',');
			(*index)++;
		}	
		if(*(index+1) < (10-1))
		{
			(*(index+1))++;
			*index = *(index+1) +1; 	
		}
	}
	
	else if (n > 1)
	{
		while ((*index) < (10 - n))
		{
			recursive(n-1, index-1);	
		}
		if(*index < (10-n))
		{
			(*(index+1))++;
			*index = n-1;
		}
	}
}
