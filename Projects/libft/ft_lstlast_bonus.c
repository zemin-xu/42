/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:13:09 by zexu              #+#    #+#             */
/*   Updated: 2019/10/31 11:04:49 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list				*ft_lstlast(t_list *lst)
{
	t_list			*curr_list;

	if ((curr_list = lst) == NULL)
		return (NULL);
	while(curr_list->next)
		curr_list = curr_list->next;
	return (curr_list);
}
