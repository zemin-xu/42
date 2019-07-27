/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trans.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:26:17 by ptang             #+#    #+#             */
/*   Updated: 2019/06/26 23:06:45 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

void		trans_line(char *line, int *res, int n)
{
	int		i;

	i = 0;
	while (i < n)
	{
		if (*(line + i) == 'o')
			*(res + i) = 0;
		else
			*(res + i) = 1;
		i++;
	}
}

void		pass_line(int *src, int *dest, int n)
{
	int		i;

	i = 1;
	while (i <= n)
	{
		*(dest + i) = *(src + i);
		i++;
	}
}
