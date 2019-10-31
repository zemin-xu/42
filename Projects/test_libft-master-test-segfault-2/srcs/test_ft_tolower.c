/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_tolower.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:41:50 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/09 10:13:06 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_tolower(void)
{
	printf("test ft_tolower\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(tolower(g_test_id), ft_tolower(g_test_id));
		g_test_id++;
	}
}
