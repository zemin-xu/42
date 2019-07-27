/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:55:14 by zexu              #+#    #+#             */
/*   Updated: 2019/06/23 23:08:06 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int			size_num(char *str)
{
	int		size;

	if (num_len(str) % 3 == 1)
		size = num_len(str) + 2;
	else if (num_len(str) % 3 == 2)
		size = num_len(str) + 1;
	else
		size = num_len(str);
	return (size);
}

char		*add_zero(char *str)
{
	int		size;
	char	*buf;
	int		i;

	i = 0;
	size = size_num(str);
	buf = malloc(sizeof(*buf) * (1 + size));
	if (num_len(str) % 3 == 1)
	{
		buf[0] = '0';
		buf[1] = '0';
		i = 2;
	}
	else if (num_len(str) % 3 == 2)
	{
		buf[0] = '0';
		i = 1;
	}
	while (str[i - (3 - (num_len(str) % 3 == 0 ? 3 : num_len(str) % 3))])
	{
		buf[i] = str[i - (3 - (num_len(str) % 3 == 0 ? 3 : num_len(str) % 3))];
		i++;
	}
	buf[i] = '\0';
	return (buf);
}

char		**split_3(char *str)
{
	char	**res;
	int		division;
	int		i;
	int		j;

	if ((num_len(str) % 3) != 0)
		division = num_len(str) / 3 + 1;
	else
		division = num_len(str) / 3;
	res = malloc(sizeof(char *) * division);
	i = -1;
	while (i < division)
		res[++i] = malloc(sizeof(char) * 3);
	i = 0;
	while (i < division)
	{
		j = 0;
		while (j < 3)
		{
			res[i][j] = str[(i) * 3 + (j)];
			j++;
		}
		i++;
	}
	return (res);
}

int			num_div(char *str)
{
	int		size;

	if (num_len(str) % 3 == 1)
		size = num_len(str) + 2;
	else if (num_len(str) % 3 == 2)
		size = num_len(str) + 1;
	else
		size = num_len(str);
	return (size / 3);
}

int			test_num(char *num)
{
	int		i;

	i = 0;
	while (num[i])
	{
		if (num[i] >= '0' && num[i] <= '9')
			i++;
		else
			return (-1);
	}
	if ((num[0] == '0' && i > 1) || i > 39)
		return (-1);
	else
		return (0);
}
