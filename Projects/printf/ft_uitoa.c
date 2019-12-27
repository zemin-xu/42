/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uitoa.c                                          :+:      :+:    :+:   */
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

#include "ft_printf.h"

static int			length(unsigned int n)
{
	long			tmp;
	int				count;

	tmp = (long)n;
	count = 1;
	while (tmp >= 10)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

char				*ft_uitoa(unsigned int n)
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
	while (len > i)
	{
		*(str + --len) = '0' + tmp % 10;
		tmp /= 10;
	}
	return (str);
}
