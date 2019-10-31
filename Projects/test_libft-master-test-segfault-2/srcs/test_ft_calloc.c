/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_calloc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:25:12 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/10 17:38:21 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	test_ft_calloc(void)
{
	printf("test ft_calloc\n");
	g_test_id = 1;//1
	void *ptr1 = calloc(5, 5);
	void *ptr2 = ft_calloc(5, 5);
	mem_comp(ptr1, ptr2, 25);
}
