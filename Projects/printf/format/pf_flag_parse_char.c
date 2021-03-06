/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_parse_char.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:51:31 by zexu              #+#    #+#             */
/*   Updated: 2020/05/05 16:51:36 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

void				pf_flag_parse_s(t_pf *list)
{
	size_t			str_len;
	size_t			pad_len;

	str_len = ft_strlen(list->str_before);
	pad_len = 0;
	if (list->precise_num != -1 && (int)str_len > list->precise_num)
		str_len = list->precise_num;
	if (list->pad_num != -1 && (int)str_len < list->pad_num)
		pad_len = list->pad_num - str_len;
	if (list->is_left_justified)
		list->str_after = pf_join_with_pad_space(list->str_before,
												str_len, pad_len, 1);
	else
		list->str_after = pf_join_with_pad_space(list->str_before,
												str_len, pad_len, 0);
	list->len = ft_strlen(list->str_after);
}

void				pf_flag_parse_c(t_pf *list)
{
	size_t			str_len;
	size_t			pad_len;

	str_len = 1;
	pad_len = 0;
	if (list->pad_num != -1 && (int)str_len < list->pad_num)
		pad_len = list->pad_num - str_len;
	if (*(list->str_before) == '\0')
	{
		list->str_after = pf_join_pad_c_null(pad_len, list->is_left_justified);
		list->len = 1 + pad_len;
	}
	else
	{
		if (list->is_left_justified)
			list->str_after = pf_join_with_pad_space(list->str_before,
												str_len, pad_len, 1);
		else
			list->str_after = pf_join_with_pad_space(list->str_before,
												str_len, pad_len, 0);
		list->len = ft_strlen(list->str_after);
	}
}

void				pf_flag_parse_per(t_pf *list)
{
	int				str_len;
	int				pad_len;

	str_len = 1;
	pad_len = 0;
	if ((list->pad_num - str_len) > 0)
		pad_len = list->pad_num - str_len;
	if (!list->is_left_justified && list->is_padded_with_zero)
		list->str_after = pf_join_with_pad_zero(list->str_before,
												str_len, pad_len, 0);
	else if (!list->is_left_justified)
		list->str_after = pf_join_with_pad_space(list->str_before,
												str_len, pad_len, 0);
	else
		list->str_after = pf_join_with_pad_space(list->str_before,
												str_len, pad_len, 1);
	list->len = ft_strlen(list->str_after);
}
