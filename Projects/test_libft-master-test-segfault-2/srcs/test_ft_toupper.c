/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_toupper.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:42:08 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/09 10:05:48 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_toupper(void)
{
	printf("test ft_toupper\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(toupper(g_test_id), ft_toupper(g_test_id));
		g_test_id++;
	}
}
