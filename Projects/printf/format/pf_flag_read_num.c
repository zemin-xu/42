/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_read_num.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:15:47 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:15:48 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

void	pf_flag_read_char(t_pf *new, char num)
{
	if (new->precise_num != -1)
		new->precise_num = new->precise_num * 10 + num - '0';
	else
	{
		if (new->pad_num == -1)
		{
			new->pad_num = 0;
			if (num == '0')
				new->is_padded_with_zero = 1;
		}
		new->pad_num = new->pad_num * 10 + num - '0';
	}
}

void	pf_flag_read_int(t_pf *new, int num)
{
	if (new->precise_num == 0)
	{
		if (num >= 0)
			new->precise_num = num;
		else
			new->precise_num = -1;
	}
	else
	{
		if (num < 0)
		{
			new->is_left_justified = 1;
			new->pad_num = -num;
		}
		else
			new->pad_num = num;
	}
}
