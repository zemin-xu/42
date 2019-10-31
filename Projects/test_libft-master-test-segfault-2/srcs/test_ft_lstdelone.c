/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstdelone.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:30:39 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 14:12:59 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void del(void *content)
{
	*((int *)(content)) = 101;
}

void	test_ft_lstdelone(void)
{
	printf("test ft_lstdelone\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void *)integers));
	ft_lstdelone(lst, &del);
	g_test_id = 1;//1
	int_comp(101, integers[0]);
}
