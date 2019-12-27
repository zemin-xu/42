/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:38:03 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 13:38:15 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a new created string ending with '\0' representing
** the integer 'n' given as argument.
*/

#include "ft_utils.h"

static int			length(unsigned long n)
{
	long			tmp;
	int				count;

	tmp = n;
	count = 3;
	while (tmp >= 16)
	{
		tmp /= 16;
		count++;
	}
	return (count);
}

char				*ft_ptoa(void *n)
{
	int				len;
	int				i;
	char			*str;
	long			tmp;

	tmp = (unsigned long)n;
	len = length(tmp);
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	*(str + len) = '\0';
	i = 2;
	while (len > i)
	{
		if (tmp % 16 < 10)
			*(str + --len) = '0' + tmp % 16;
		else
			*(str + --len) = 'a' + (tmp % 16) - 10;
		tmp /= 16;
	}
	*str = '0';
	*(str + 1) = 'x';
	return (str);
}
