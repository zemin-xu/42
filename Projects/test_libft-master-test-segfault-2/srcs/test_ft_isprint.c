/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isprint.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:28:22 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 16:23:56 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_isprint(void)
{
	printf("test ft_isprint\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(isprint(g_test_id), ft_isprint(g_test_id));
		g_test_id++;
	}
}
