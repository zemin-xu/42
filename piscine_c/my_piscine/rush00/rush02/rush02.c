/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:09:27 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 17:47:39 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void		ft_putchar(char c);

void		rush02(int x, int y)
{
	int		a;
	int		b;

	a = 1;
	b = 1;
	while (b <= y)
	{
		while (a <= x)
		{
			if ((a == 1 && b == 1) || (a == x && b == 1))
				ft_putchar('A');
			else if ((a == 1 && b == y) || (a == x && b == y))
				ft_putchar('C');
			else
				ft_putchar((b == 1 || b == y || a == 1 || a == x) ? 'B' : ' ');
			a++;
		}
		ft_putchar('\n');
		b++;
		a = 1;
	}
}