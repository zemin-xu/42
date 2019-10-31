/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:21:36 by zexu              #+#    #+#             */
/*   Updated: 2019/10/31 11:30:46 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** delete and free the given element and every successor of that element,
** using the function 'del' and free, the pointer to the list must be set to
** NULL finally
*/

#include "libft.h"

void				ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list			*tmp;
	t_list			**head;

	if (lst && del)
	{
		head = lst;
		while (*lst != NULL)
		{
			tmp = *lst;
			*lst = (*lst)->next;
			del(tmp->content);
			free(tmp);
		}
		head = NULL;
	}
}
