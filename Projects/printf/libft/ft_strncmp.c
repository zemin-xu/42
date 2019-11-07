/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:23:55 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 10:24:21 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	if (size == 0)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
	{
		if (i < size - 1)
			i++;
		else
			return (0);
	}
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
