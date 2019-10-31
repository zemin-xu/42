/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_lstsize.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:32:32 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/16 13:41:47 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_lstsize(void)
{
	printf("test ft_lstsize\n");
	int	integers[3] = {42, 1764, 74088};
	t_list	*lst;
	lst = NULL;
	ft_lstadd_front(&lst, ft_lstnew((void *)integers));
	ft_lstadd_front(&lst, ft_lstnew((void *)(integers + 1)));
	ft_lstadd_front(&lst, ft_lstnew((void *)(integers + 2)));
	g_test_id = 1;//1
	int_comp(3, ft_lstsize(lst));
	g_test_id++;//2
	int_comp(0, ft_lstsize(NULL));
}
