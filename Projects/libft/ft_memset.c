/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:59:02 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 13:44:35 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** copy the value of 'c' (converted to an unsigned char) into each of the
** first 'size' bytes of the object beginning at 'block'
**
** return the value of 'block'
*/

#include "libft.h"

void				*ft_memset(void *block, int c, size_t size)
{
	char			*p;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	p = (char *)block;
	i = 0;
	while (i < size)
	{
		*(p + i) = c;
		i++;
	}
	return (block);
}
