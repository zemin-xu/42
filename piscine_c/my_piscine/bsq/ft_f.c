/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_f.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:24:47 by ptang             #+#    #+#             */
/*   Updated: 2019/06/26 23:25:41 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_atoi(char *str)
{
	int i;
	int sign;
	int result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + str[i] - '0';
		i++;
	}
	return (result * sign);
}

void    ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}





void		print_res(int *res, char **map)
{
	int     x;
	int     y;

	x = 0;
	y = 0;
	while (y < res[1])
	{
		x = 0;
		while (x < res[1])
		{
			if((x >= (res[3] - res[2])) && (x < res[3]) &&
					(y >= (res[4] - res[2])) && (y < res[4]))
				ft_putchar('x');
			else
				ft_putchar(map[x][y]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
