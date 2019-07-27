/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   value.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:27:44 by ptang             #+#    #+#             */
/*   Updated: 2019/06/26 23:13:46 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int			min(int a, int b, int c)
{
	if ((a - b) < 0)
	{
		return ((a - c) < 0 ? a : c);
	}
	else
	{
		return ((b - c) < 0 ? b : c);
	}
}

void		pass_value(int *a, int x, int y, int value)
{
	*a = value;
	*(a + 1) = x;
	*(a + 2) = y;
}

void		pass_max(int *max, int *cur)
{
	*max = *cur;
	*(max + 1) = *(cur + 1);
	*(max + 2) = *(cur + 2);
}
