/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:27:46 by zexu              #+#    #+#             */
/*   Updated: 2019/06/21 11:27:43 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int	i;
	int	*p_int;

	p_int = NULL;
	if (min >= max)
		return (p_int);
	else
	{
		i = max - min;
		if ((p_int = malloc(sizeof(*p_int) * i)) == NULL)
			return (NULL);
		while (i > 0)
		{
			*(p_int + i - 1) = i + min - 1;
			i--;
		}
		return (p_int);
	}
}
