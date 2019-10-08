/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:13:21 by zexu              #+#    #+#             */
/*   Updated: 2019/10/08 22:02:41 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** a subset of memset
**
** copy the value of zero (converted to an unsigned char) into each of the
** first 'size' bytes of the object beginning at 'block'
*/

#include "libft.h"

void		ft_bzero(void *block, size_t size)
{
	char			*p;
	size_t			i;

	p = (char *)block;
	if (p == NULL)
		return ;
	i = 0;
	while (i < size)
	{
		*(p + i) = '\0';
		i++;
	}
}
