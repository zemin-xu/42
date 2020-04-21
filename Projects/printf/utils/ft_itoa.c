/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:03 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:14:25 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a new created string ending with '\0' representing
** the integer 'n' given as argument.
**
** The itoa here will not display '-', for collaboration with printf.
*/

#include "pf_utils.h"

static int			length(int n)
{
	long			tmp;
	int				count;

	tmp = (long)n;
	count = 1;
	if (tmp < 0)
	{
		tmp *= -1;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*str;
	long			tmp;

	len = length(n);
	tmp = (long)n;
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	*(str + len) = '\0';
	i = 0;
	if (tmp < 0)
	{
		tmp *= -1;
	}
	while (len > i)
	{
		*(str + --len) = '0' + tmp % 10;
		tmp /= 10;
	}
	return (str);
}
