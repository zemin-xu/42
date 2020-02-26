/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hextoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:12:51 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:12:59 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a new created string ending with '\0' representing
** the integer 'n' given as argument.
*/

#include "pf_utils.h"

static int			length(unsigned int n)
{
	long			tmp;
	int				count;

	tmp = (long)n;
	count = 1;
	while (tmp >= 16)
	{
		tmp /= 16;
		count++;
	}
	return (count);
}

char				*ft_hextoa(unsigned int n, int is_maj)
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
		if (tmp % 16 < 10)
			*(str + --len) = '0' + (tmp % 16);
		else
		{
			if (is_maj)
				*(str + --len) = 'A' + (tmp % 16) - 10;
			else
				*(str + --len) = 'a' + (tmp % 16) - 10;
		}
		tmp /= 16;
	}
	return (str);
}
