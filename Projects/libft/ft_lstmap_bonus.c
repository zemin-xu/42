/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/20 18:10:32 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 10:43:39 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** iterate the list 'lst' and apply the function 'f' to the content of each
** element. create a new list resulting of the successive application of it
**
** 'del' function is here to delete the content of an element if needed
*/

#include "libft.h"
/*
t_list				*ft_listmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	int				size;
	int				i;

	i = 0;
	if (lst == NULL)
		return ;
	size = ft_lstsize(lst);
	
	while (i < size)
	{
		f(curr_list->data);
		curr_list = curr_list->next;
	}
}
*/
