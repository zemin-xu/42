/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:26:36 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 15:58:49 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_isalpha(void)
{
	printf("test ft_isalpha\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(isalpha(g_test_id), ft_isalpha(g_test_id));
		g_test_id++;
	}
}
