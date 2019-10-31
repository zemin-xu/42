/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstclear.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:30:04 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 15:57:52 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void del(void *content)
{
	*((int *)(content)) = 101;
}

void	test_ft_lstclear(void)
{
	printf("test ft_lstclear\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void *)integers));
	ft_lstadd_back(&lst, ft_lstnew((void *)(integers + 1)));
	ft_lstadd_back(&lst, ft_lstnew((void *)(integers + 2)));
	ft_lstclear(&lst, &del);
	g_test_id = 1;
	int	i = 0;
	while (i < 3)
	{
		int_comp(101, integers[i]);
		i++;
		g_test_id++;
	}
	ptr_comp(NULL, lst, 1);
}
