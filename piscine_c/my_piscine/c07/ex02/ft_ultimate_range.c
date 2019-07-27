/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 11:27:06 by zexu              #+#    #+#             */
/*   Updated: 2019/06/24 10:20:52 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int	i;
	int	*p_int;

	p_int = NULL;
	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	else
	{
		i = min;
		if ((p_int = malloc(sizeof(int) * (max - min + 1))) == NULL)
		{
			*range = NULL;
			return (-1);
		}
		while (i < max)
		{
			*(p_int + i - min) = i;
			i++;
		}
		*range = p_int;
		return (i - min);
	}
}
