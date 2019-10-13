/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:24:47 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 22:46:32 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list			*curr_list;

	if ((curr_list = lst) == NULL)
		return ;
	while (curr_list)
	{
		f(curr_list->content);
		curr_list = curr_list->next;
	}
}
