/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isdigit.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:27:43 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 15:59:04 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_isdigit(void)
{
	printf("test ft_isdigit\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(isdigit(g_test_id), ft_isdigit(g_test_id));
		g_test_id++;
	}
}
