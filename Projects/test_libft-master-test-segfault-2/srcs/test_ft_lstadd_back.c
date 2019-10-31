/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_back.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:29:02 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 13:58:24 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_lstadd_back(void)
{
	printf("test ft_lstadd_back\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void *)integers));
	ft_lstadd_back(&lst, ft_lstnew((void *)(integers + 1)));
	ft_lstadd_back(&lst, ft_lstnew((void *)(integers + 2)));
	g_test_id = 1;
	int	i = 0;
	while (lst)
	{
		ptr_comp(integers + i, (int *)(lst->content), 1);
		int_comp(*(integers + i), *((int *)(lst->content)));
		i++;
		lst = lst->next;
		g_test_id++;
	}
}
