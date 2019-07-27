/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 21:52:59 by zexu              #+#    #+#             */
/*   Updated: 2019/06/23 23:08:08 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
	}
}

int			num_len(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char		**create_lib_2(char *buffer, int fd, char **res)
{
	int a[5];

	a[1] = 0;
	a[4] = 0;
	while ((a[0] = read(fd, buffer, 1000)) != 0)
	{
		while (a[1] < a[0])
		{
			if (buffer[a[1]] == ':')
			{
				a[2] = a[1] + 2;
				a[3] = 0;
				while (buffer[a[2]] != '\n')
				{
					res[a[4]][a[3]] = buffer[a[2]];
					a[3]++;
					a[2]++;
				}
				a[4]++;
			}
			a[1]++;
		}
	}
	return (res);
}

char		**create_lib(int fd)
{
	char	**res;
	char	buffer[1000];
	int		a;

	a = 0;
	res = malloc(sizeof(char *) * 41);
	while (a < 41)
	{
		res[a] = malloc(sizeof(char) * 100);
		a++;
	}
	res = create_lib_2(buffer, fd, res);
	return (res);
}
