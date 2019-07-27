/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 12:16:20 by zexu              #+#    #+#             */
/*   Updated: 2019/06/17 21:28:08 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		check_base(char *base)
{
	int a;
	int b;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	a = 0;
	while (base[a])
	{
		if (base[a + 1])
		{
			b = a + 1;
			while (base[b])
			{
				if (base[b] == base[a])
					return (0);
				b++;
			}
		}
		if (base[a] == '+' || base[a] == '-' || base[a] == '.' ||
		base[a] < ' ' || base[a] > '~')
			return (0);
		a++;
	}
	return (a);
}

void	treat_nb(int nbr, int size, char *base)
{
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		treat_nb((2147483648 - size) / size + 1, size, base);
		ft_putchar(base[(2147483648 - size) % size]);
	}
	else
	{
		if (nbr < 0)
		{
			ft_putchar('-');
			nbr *= -1;
		}
		if (nbr >= size)
		{
			treat_nb(nbr / size, size, base);
			ft_putchar(base[nbr % size]);
		}
		else
			ft_putchar(base[(nbr) % size]);
	}
}

void	ft_putnbr_base(int nbr, char *base)
{
	int size;

	if ((size = check_base(base)) == 0)
		ft_putchar('\0');
	else
		treat_nb(nbr, size, base);
}
