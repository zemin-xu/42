/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 19:56:27 by zexu              #+#    #+#             */
/*   Updated: 2019/06/25 20:33:48 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include "ft_stock_str.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void		ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

void		ft_show_tab(struct s_stock_str *par)
{
	int		i;

	if (par == NULL)
		return ;
	i = 0;
	while ((par + i)->str)
	{
		ft_putstr((par + i)->str);
		ft_putchar('\n');
		ft_putnbr((par + i)->size);
		ft_putchar('\n');
		ft_putstr((par + i)->copy);
		ft_putchar('\n');
		i++;
	}
}
