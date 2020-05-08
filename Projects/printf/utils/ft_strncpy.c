/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/08 23:53:58 by zexu              #+#    #+#             */
/*   Updated: 2020/05/08 23:54:21 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_utils.h"

char				*ft_strncpy(char *to, const char *from,
						size_t size)
{
	unsigned int	i;

	i = 0;
	while (from[i] && i < size)
	{
		to[i] = from[i];
		i++;
	}
	while (i < size)
	{
		to[i] = '\0';
		i++;
	}
	return (to);
}
