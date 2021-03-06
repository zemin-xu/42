/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:16:09 by zexu              #+#    #+#             */
/*   Updated: 2019/11/09 11:51:20 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** free the memory of the element 'lst''s content using the function 'del'
** as a parameter
**
** the memory of 'next' must not be freed under any circumstance
*/

#include "libft.h"

void				ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (del == NULL || lst == NULL)
		return ;
	del(lst->content);
	free(lst);
}
