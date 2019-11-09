/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:10:32 by zexu              #+#    #+#             */
/*   Updated: 2019/11/09 11:41:05 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** iterate the list 'lst' and apply the function 'f' to the content of each
** element. create a new list resulting of the successive application of it
**
** 'del' function is here to delete the content of an element if needed
*/

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*prev_list;
	t_list	*curr_list;
	t_list	*head;

	if (lst == 0)
		return (0);
	prev_list = 0;
	if (!(curr_list = ft_lstnew(f(lst->content))))
		return (0);
	head = curr_list;
	lst = lst->next;
	while (lst)
	{
		prev_list = curr_list;
		if (!(curr_list = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&head, del);
			return (0);
		}
		prev_list->next = curr_list;
		lst = lst->next;
	}
	return (head);
}
