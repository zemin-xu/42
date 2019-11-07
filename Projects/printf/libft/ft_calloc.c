/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 12:35:11 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 13:13:55 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate a block long enough to contain a vector of 'count' element,
** each of size 'elesize'
*/

#include "libft.h"

static void			*inner_memset(void *block, int c, size_t size)
{
	char			*p;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	p = (char *)block;
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(p + i) = c;
		i++;
	}
	return (block);
}

void				*ft_calloc(size_t count, size_t eltsize)
{
	size_t			size;
	void			*block;

	size = count * eltsize;
	if ((block = malloc(size)) != NULL)
		inner_memset(block, 0, size);
	return (block);
}
