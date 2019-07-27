/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 21:19:45 by zexu              #+#    #+#             */
/*   Updated: 2019/06/24 10:19:28 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*treat_nb(int nbr, int size, char *base);
char		*ft_putnbr_base(int nbr, char *base);

int			check_base(char *base)
{
	int		a;
	int		b;

	if (base[0] == '\0' || base[1] == '\0')
		return (0);
	a = 0;
	while (base[a])
	{
		if (base[a])
		{
			b = a + 1;
			while (base[b])
			{
				if (base[b] == base[a])
					return (0);
				b++;
			}
		}
		if (base[a] == '+' || base[a] == '-' || base[a] == '.'
				|| base[a] <= ' ' || base[a] > '~')
			return (0);
		a++;
	}
	return (a);
}

void		intermediaire(char *str, int *c, int *sign)
{
	while (str[*c] == ' ' || str[*c] == '\t' || str[*c] == '\n'
			|| str[*c] == '\v' || str[*c] == '\f' || str[*c] == '\r')
		(*c)++;
	while (str[*c] == '+' || str[*c] == '-')
	{
		*(sign) *= ((str[*c] == '-') ? -1 : 1);
		(*c)++;
	}
}

int			ft_atoi_base(char *str, char *base)
{
	int		a[4];

	a[3] = 1;
	a[0] = 0;
	a[1] = 0;
	if (check_base(base) == 0)
		return (0);
	intermediaire(str, &a[1], &a[3]);
	while (str[a[1]])
	{
		a[2] = 0;
		while (a[2] < check_base(base))
		{
			if (str[a[1]] == base[a[2]])
			{
				a[0] = a[0] * check_base(base) + a[2];
				break ;
			}
			if (++a[2] == check_base(base))
				return (a[0] * a[3]);
		}
		a[1]++;
	}
	return (a[0] * a[3]);
}

char		*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	char	*res;

	if (check_base(base_from) == 0 || check_base(base_to) == 0)
		return (NULL);
	i = ft_atoi_base(nbr, base_from);
	res = ft_putnbr_base(i, base_to);
	return (res);
}
