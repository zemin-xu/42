/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:12:07 by zexu              #+#    #+#             */
/*   Updated: 2019/10/31 13:30:39 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int				ft_lstsize(t_list *lst)
{
	t_list		*curr_list;
	int			i;

	if ((curr_list = lst) == NULL)
		return (0);
	i = 0;
	while (curr_list)
	{
		curr_list = curr_list->next;
		i++;
	}
	return (i);
}
