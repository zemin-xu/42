/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:14:27 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 22:43:05 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add the element 'new' at the end of the list
*/

#include "libft.h"

void				ft_lst_back(t_list **alst, t_list *new)
{
	if ((new = *alst) == NULL)
		*alst = new;
	else
	{
		while (new->next)
			new = new->next;
		new->next = new;
	}
}
