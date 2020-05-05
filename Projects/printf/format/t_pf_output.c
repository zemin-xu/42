/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pf_output.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:52:58 by zexu              #+#    #+#             */
/*   Updated: 2020/05/05 16:53:00 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

void		t_pf_flag_parse(t_pf *head)
{
	t_pf	*curr;

	if (!(curr = head))
		return ;
	while (curr)
	{
		if (curr->has_flag)
		{
			if (curr->format_type == 's')
				pf_flag_parse_s(curr);
			else if (curr->format_type == 'c')
				pf_flag_parse_c(curr);
			else if (curr->format_type == 'i' || curr->format_type == 'd'
			|| curr->format_type == 'u' || curr->format_type == '%'
			|| curr->format_type == 'p' || curr->format_type == 'x'
			|| curr->format_type == 'X')
				pf_flag_parse_i(curr);
		}
		curr = curr->next;
	}
}

int			t_pf_output(t_pf *head)
{
	t_pf	*curr;
	int		count;

	count = 0;
	if (!(curr = head))
		return (-1);
	while (curr)
	{
		if (!curr->has_flag)
			ft_putstr_fd(curr->str_before, 1);
		else
			ft_putstr_fd(curr->str_after, 1);
		count += curr->len;
		curr = curr->next;
	}
	return (count);
}
