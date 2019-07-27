/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 23:38:15 by zexu              #+#    #+#             */
/*   Updated: 2019/06/06 07:20:50 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
void ft_putnbr(int nb);
void ft_putchar(char c)
{
	write(1, &c, 1);
}


void ft_nb_not_positive(int *tmp)
{
	if(*tmp < 0)
	{
		ft_putchar('-');
		*tmp *= -1;		
	}
}

void ft_putnbr(int nb)
{
	int 	array[20];
	int		tmp;
	int		i;

	i = 0;
	tmp = nb;
	ft_nb_not_positive(&tmp);
	while (tmp >= 0)
	{
		array[i] = tmp % 10;
		tmp -= array[i];
		if (tmp == 0)
		{
			break ;
		}	
		tmp /= 10;
		i++;
	}

	while (i >= 0)
	{
		ft_putchar('0' + array[i]);
		i--;
	}
}

