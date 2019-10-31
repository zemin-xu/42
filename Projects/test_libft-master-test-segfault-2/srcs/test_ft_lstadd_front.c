/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstadd_front.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:29:32 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 13:32:04 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_lstadd_front(void)
{
	printf("test ft_lstadd_front\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew((void *)integers));
	ft_lstadd_front(&lst, ft_lstnew((void *)(integers + 1)));
	ft_lstadd_front(&lst, ft_lstnew((void *)(integers + 2)));
	g_test_id = 1;
	int	i = 2;
	while (lst)
	{
		ptr_comp(integers + i, (int *)(lst->content), 1);
		int_comp(*(integers + i), *((int *)(lst->content)));
		i--;
		lst = lst->next;
		g_test_id++;
	}
}
