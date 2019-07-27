/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 12:22:58 by zexu              #+#    #+#             */
/*   Updated: 2019/06/10 12:21:33 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_decimal_to_hexa(int nb)
{
	char	list[16];
	int		a;

	a = 0;
	while (a < 10)
	{
		list[a] = '0' + a;
		a++;
	}
	while (a < 16)
	{
		list[a] = 'a' + a - 10;
		a++;
	}
	ft_putchar('\\');
	if (nb < 16)
		ft_putchar('0');
	while (nb >= 16)
	{
		a = nb / 16;
		ft_putchar(list[a]);
		nb -= a * 16;
	}
	if (nb < 16)
		ft_putchar(list[nb % 16 - 1]);
}

void		ft_putstr_non_printable(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] < ' ' || str[i] > '~')
		{
			ft_decimal_to_hexa(str[i] - '\0' + 1);
			i++;
			continue ;
		}
		ft_putchar(str[i]);
		i++;
	}
}
