/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:10:32 by zexu              #+#    #+#             */
/*   Updated: 2019/11/01 16:16:28 by zexu             ###   ########.fr       */
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
	t_list	*head_list;
	t_list	*curr_list;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	if ((head_list = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	head_list->next = curr_list;
	while (lst->next != NULL)
	{
		lst = lst->next;
		if ((curr_list = ft_lstnew(f(curr_list->content))) == NULL)
		{
			ft_lstclear(&head_list, del);
			return (NULL);
		}
		curr_list = curr_list->next;
	}
	return (head_list);
}
