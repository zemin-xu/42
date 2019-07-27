/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/20 11:39:57 by zexu              #+#    #+#             */
/*   Updated: 2019/06/26 19:00:18 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			check_base(char *base);

int			count_length(int nbr, int size)
{
	int		i;
	long	tmp;

	i = 0;
	tmp = (long)nbr;
	if (tmp == 0)
		return (1);
	if (tmp < 0)
	{
		tmp *= -1;
		i++;
	}
	while (tmp > 0)
	{
		tmp /= size;
		i++;
	}
	return (i);
}

char		*treat_nb(int nbr, char *res, char *base)
{
	int		i;
	long	tmp;
	int		size;

	size = check_base(base);
	i = count_length(nbr, size) - 1;
	tmp = nbr;
	if (tmp < 0)
	{
		*(res + 0) = '-';
		tmp *= -1;
	}
	while (tmp >= size)
	{
		*(res + i) = *(base + (tmp % size));
		tmp /= size;
		i--;
	}
	*(res + i) = *(base + (tmp % size));
	return (res);
}

char		*ft_putnbr_base(int nbr, char *base)
{
	int		size;
	char	*res;
	int		length_str;

	size = check_base(base);
	length_str = count_length(nbr, size);
	if (size == 0)
		return (NULL);
	else
	{
		if (res = malloc(sizeof(char) * (length_str + 1)) == NULL)
			return (NULL);
		res = treat_nb(nbr, res, base);
		*(res + length_str) = '\0';
		return (res);
	}
}
