/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:14:27 by zexu              #+#    #+#             */
/*   Updated: 2019/10/31 11:13:33 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** add the element 'new' at the end of the list
 */

#include "libft.h"

// alst null
// alst with next null
//

void				ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list			*list_last;

	if (alst && new)
	{
		if (*alst == NULL)
			*alst = new;
		else
		{
			list_last = ft_lstlast(*alst);
			list_last->next = new;
		}
	}
}
