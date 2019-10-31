/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstnew.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:32:10 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 13:34:21 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_lstnew(void)
{
	printf("test ft_lstnew\n");
	int	i = 42;
	t_list	*lst;
	lst = ft_lstnew((void *)&i);
	g_test_id = 1;//1
	ptr_comp((void *)&i, lst->content, 1);
	g_test_id++;//2
	int_comp(i, *((int *)(lst->content)));
	g_test_id++;//3
	ptr_comp(NULL, lst->next, 1);
}
