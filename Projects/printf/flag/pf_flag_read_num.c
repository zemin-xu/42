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

#include "pf_flag.h"

/*
void pf_flag_read_char(t_flag *flag, char num)
{
	if (flag->is_precised)
		flag->precise_num = flag->precise_num * 10 + num - '0';
	else
	{
		if (flag->pad_num == 0 && num == '0')
			flag->is_padded = 2;
		else
		{
			if (flag->is_padded != 2)
				flag->is_padded = 1;
		}
		flag->pad_num = flag->pad_num * 10 + num - '0';
	}
}

void pf_flag_read_int(t_flag *flag, int num)
{
	if (flag->is_precised)
		flag->precise_num = num;
	else
	{
		flag->is_padded = 1;
		flag->pad_num = num;
	}
}
*/
