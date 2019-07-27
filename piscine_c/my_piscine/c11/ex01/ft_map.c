/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 15:33:57 by zexu              #+#    #+#             */
/*   Updated: 2019/06/24 15:54:24 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			*ft_map(int *tab, int length, int (*f)(int))
{
	int		i;
	int		*res;

	res = malloc(sizeof(*tab) * length);
	i = 0;
	while (i < length)
	{
		*(res + i) = (*f)(tab[i]);
		i++;
	}
	return (res);
}
