/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 18:13:21 by zexu              #+#    #+#             */
/*   Updated: 2019/10/07 18:13:25 by zexu             ###   ########.fr       */
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
	ft_memset(block, 0, size);
}
