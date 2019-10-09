/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:11:18 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 10:11:22 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** find the first occurrence of the byte 'c' in the initial 'size'
** bytes of the object beginning at 'block'
**
** return a pointer to the located byte, or a null pointer if no match
** was found
*/

#include "libft.h"

void				*ft_memchr(const void *block, int c, size_t size)
{
	size_t			i;
	char			*c_block;

	i = 0;
	c_block = (char *)block;
	while (i < size)
	{
		if (*(c_block + i) == c)
			return ((void *)(c_block + i));
		i++;
	}
	return (NULL);
}
