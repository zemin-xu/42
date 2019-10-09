/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:12:20 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 10:07:00 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** append the nul-terminated string 'from' to the end of 'to'
** at most 'size - strlen(to) - 1' bytes, nul-terminating the result
**
** return the initial length of 'to' plus the length of 'from'
**
** if the 'size' is less than or equal to the size of 'to', the string of 'to'
** will not be changed and it will return the size of 'from' plus 'size'
*/

#include "libft.h"

static size_t		len(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t				ft_strlcat(char *to, const char *from, size_t size)
{
	size_t			length;
	size_t			i;

	length = len(to);
	if (length >= size)
		return (len(from) + size);
	else
	{
		i = 0;
		while (*(from + i) && i < size - length - 1)
		{
			*(to + length + i) = *(from + i);
			i++;
		}
		*(to + length + i) = '\0';
	}
	return (length + len(from));
}
