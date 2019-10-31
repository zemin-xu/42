/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstlast.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:31:20 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 13:55:19 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_lstlast(void)
{
	printf("test ft_lstlast\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew((void *)integers));
	ft_lstadd_front(&lst, ft_lstnew((void *)(integers + 1)));
	ft_lstadd_front(&lst, ft_lstnew((void *)(integers + 2)));
	g_test_id = 1;//1
	int_comp(integers[0], *((int *)ft_lstlast(lst)->content));
	g_test_id++;//2
	ptr_comp(NULL, ft_lstlast(NULL), 1);
}
