/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:58:17 by zexu              #+#    #+#             */
/*   Updated: 2019/06/23 23:28:28 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void		read_outer(char **dict, int i, int flag)
{
	if (i != 0)
	{
		if (flag == 1)
			ft_putchar(' ');
		ft_putstr(dict[i + 28]);
		if (flag == 2)
			ft_putchar(' ');
	}
}

int			read_inner(char **dict, char *inner, int division)
{
	if (inner[0] == '0' && inner[1] == '0' && inner[2] == '0' && division == 1)
	{
		ft_putstr(dict[0]);
		return (0);
	}
	else if (inner[0] == '0' && inner[1] == '0' && inner[2] == '0')
		return (0);
	if (inner[0] != '0')
	{
		ft_putstr(dict[inner[0] - '0']);
		ft_putchar(' ');
		ft_putstr(dict[28]);
		if (inner[1] != '0' || inner[2] != '0')
			ft_putchar(' ');
		if (inner[1] == 0 && inner[2] == 0)
			return (2);
	}
	return (read_inner_2(dict, inner));
}

int			read_inner_2(char **dict, char *inner)
{
	if (inner[1] != '0')
	{
		if (inner[1] == '1')
		{
			ft_putstr(dict[(inner[2] - '0') + 10]);
			return (1);
		}
		else
		{
			ft_putstr(dict[(inner[1] - '0') + 18]);
			if (inner[2] != '0')
				ft_putchar(' ');
		}
	}
	if (inner[2] != '0')
		ft_putstr(dict[(inner[2] - '0')]);
	return (1);
}

void		read_general(char **dict, char **src, int division)
{
	int i;
	int flag;

	i = 0;
	while (i < division)
	{
		flag = read_inner(dict, src[i], division);
		if (flag == 1 || flag == 2)
			read_outer(dict, division - 1 - i, flag);
		i++;
	}
	ft_putchar('\n');
}

int			main(int argc, char **argv)
{
	char	**lib;
	char	**res;

	if (argc != 2 || (test_num(argv[1]) == -1))
	{
		ft_putstr("Error\n");
		return (0);
	}
	lib = create_lib(open("numbers.dict.txt", O_RDONLY));
	res = split_3(add_zero(argv[1]));
	read_general(lib, res, num_div(argv[1]));
	return (0);
}
