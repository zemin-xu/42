/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isalnum.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:26:00 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 16:00:38 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_isalnum(void)
{
	printf("test ft_isalnum\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(isalnum(g_test_id), ft_isalnum(g_test_id));
		g_test_id++;
	}
}
