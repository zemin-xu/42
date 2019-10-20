/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/10 21:09:54 by zexu              #+#    #+#             */
/*   Updated: 2019/10/20 16:05:05 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy up to 'size' - 1 characters from 'from' to 'to'
** garantee null-termination
**
** if the the size of 'to' is smaller than the string to be copied, there
** will be buffer-overflow
**
** return the total length of string it tries to create, the length of 'from'
*/

#include "libft.h"

static size_t		inner_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t				ft_strlcpy(char *to, const char *from, size_t size)
{
	size_t			i;

	i = 0;
	if (size > 0)
	{
		while (*(from + i) != '\0' && i < (size - 1))
		{
			*(to + i) = *(from + i);
			i++;
		}
		*(to + i) = '\0';
	}
	return (inner_strlen(from));
}
