/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 21:48:02 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 22:32:58 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a new element of list
**
** the variable 'content' is initialized with that of the parameter
** the variable 'next' is initialized to NULL
*/
#include "libft.h"

t_list				*ft_lstnew(void *content)
{
	t_list			*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->content = content;
	list->next = NULL;
	return (list);
}

