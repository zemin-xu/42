/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output_parse.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:10:54 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:10:57 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

int				pf_output_flag(t_output *curr)
{
	int			count;

	if (!curr)
		return (0);
	count = curr->length;
	if (!curr->flag->has_flag)
		ft_putstr_fd(curr->content, 1);
	else if (curr->flag->is_left_justified)
	{
		if (curr->flag->is_precised)
			count += pf_precise(curr, curr->flag->precise_num);
		ft_putstr_fd(curr->content, 1);
		count += pf_output_pad(curr);
	}
	else
	{
		count += pf_output_pad(curr);
		if (curr->flag->is_precised)
			count += pf_precise(curr, curr->flag->precise_num);
		ft_putstr_fd(curr->content, 1);
	}
	return (count);
}

int				pf_output_pad(t_output *curr)
{
	if (curr->flag->is_padded == 1)
		return (pf_pad(curr, curr->flag->pad_num,
		curr->flag->precise_num, ' '));
	else if (curr->flag->is_padded == 2)
		return (pf_pad(curr, curr->flag->pad_num,
		curr->flag->precise_num, '0'));
	else
		return (0);
}

int				pf_output_print(t_output *head)
{
	int			count;
	t_output	*current;

	count = 0;
	if (!(current = head))
		return (0);
	count += pf_output_flag(current);
	while ((current = current->next) != NULL)
		count += pf_output_flag(current);
	return (count);
}
