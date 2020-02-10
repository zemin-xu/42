/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:14:49 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 14:18:38 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy 'size' bytes from the object beginning at 'from' into the object
** beginning at 'to'
**
** the behaviour of this function is undefined if the two arrays 'to'
** and 'from' overlap
**
** return the value of 'to'
*/

#include "pf_utils.h"

void				*ft_memcpy(void *to, const void *from, size_t size)
{
	size_t			i;
	unsigned char	*c_to;
	unsigned char	*c_from;

	if (to == NULL && from == NULL)
		return (NULL);
	i = 0;
	c_to = (unsigned char *)to;
	c_from = (unsigned char *)from;
	while (i < size)
	{
		*(c_to + i) = *(c_from + i);
		i++;
	}
	return (to);
}
