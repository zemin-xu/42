/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstmap.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:31:49 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/19 11:29:57 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

static void *f(void *content)
{
	int	*new_int;

	new_int = malloc(sizeof(int));
	*new_int = *((int *)(content)) + 101;
	return ((void *)new_int);
}

static void del(void *content)
{
	(void)content;
}

void	test_ft_lstmap(void)
{
	printf("test ft_lstmap\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	t_list	*new_lst;
	lst = NULL;
	ft_lstadd_back(&lst, ft_lstnew((void *)integers));
	ft_lstadd_back(&lst, ft_lstnew((void *)(integers + 1)));
	ft_lstadd_back(&lst, ft_lstnew((void *)(integers + 2)));
	new_lst = ft_lstmap(lst, &f, &del);
	g_test_id = 1;
	int	i = 0;
	while (new_lst)
	{
		int_comp(integers[i] + 101, *((int *)(new_lst->content)));
		ptr_comp(integers + i, new_lst->content, 0);
		ptr_comp(lst, new_lst, 0);
		i++;
		g_test_id++;
		new_lst = new_lst->next;
		lst = lst->next;
	}
	int_comp(3, i);
}
