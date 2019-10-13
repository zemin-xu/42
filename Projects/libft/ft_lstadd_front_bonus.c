/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 22:10:12 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 22:40:03 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** add the element 'new' at the beginning of the list
*/

#include "libft.h"

void				ft_lstadd_front(t_list **alst, t_list *new)
{
	if (*alst)
		new->next = *alst;
	*alst = new;
}
