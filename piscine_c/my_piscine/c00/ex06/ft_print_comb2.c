/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 21:09:46 by zexu              #+#    #+#             */
/*   Updated: 2019/06/07 15:51:10 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	print_num(int a, int b, int c, int d)
{
	ft_putchar('0' + a);
	ft_putchar('0' + b);
	ft_putchar(' ');
	ft_putchar('0' + c);
	ft_putchar('0' + d);
	if (a == 9 && b == 8 && c == 9 && d == 9)
	{
	}
	else
	{
		ft_putchar(',');
		ft_putchar(' ');
	}
}

void	func(int a, int b, int c, int d)
{
	while (a < 10)
	{
		while (b < 10)
		{
			while (c < 10)
			{
				while (d < 10)
				{
					print_num(a, b, c, d);
					d++;
				}
				c++;
				d = 0;
			}
			c = a;
			b++;
			d = b + 1;
		}
		a++;
		b = 0;
	}
}

void	ft_print_comb2(void)
{
	int		a;
	int		b;
	int		c;
	int		d;

	a = 0;
	b = 0;
	c = 0;
	d = 1;
	func(a, b, c, d);
}
