/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:12:36 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 10:12:41 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** compare the 'size' bytes of memory beginning at a1 against the 'size'
** bytes beginning at 'a2'
**
** return the difference between the first differing pair of bytes
** 0 if the two blocks are equal
*/

#include "libft.h"

int					ft_memcmp(const void *a1, const void *a2, size_t size)
{
	unsigned char	*p1;
	unsigned char	*p2;

	p1 = (unsigned char *)a1;
	p2 = (unsigned char *)a2;
	if (p1 == p2 || size == 0)
		return (0);
	while (size > 0)
	{
		if (*p1 != *p2)
			return (*p1 - *p2);
		p1++;
		p2++;
		size--;
	}
	return (0);
}
