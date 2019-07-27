/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/05 17:49:15 by zexu              #+#    #+#             */
/*   Updated: 2019/06/08 20:14:31 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		print_num(int x, int y, int z)
{
	ft_putchar('0' + x);
	ft_putchar('0' + y);
	ft_putchar('0' + z);
}

void		func(int x, int y, int z)
{
	while (x < 8)
	{
		while (y < 9)
		{
			while (z < 10)
			{
				print_num(x, y, z);
				if (x == 7 && y == 8 && z == 9)
					break ;
				else
				{
					ft_putchar(',');
					ft_putchar(' ');
					z++;
				}
			}
			y++;
			z = y + 1;
		}
		x++;
		y = x + 1;
		z = y + 1;
	}
}

void		ft_print_comb(void)
{
	int		first_num;
	int		second_num;
	int		third_num;

	first_num = 0;
	second_num = 1;
	third_num = 2;
	func(first_num, second_num, third_num);
}
