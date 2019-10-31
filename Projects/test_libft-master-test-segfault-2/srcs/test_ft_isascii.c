/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_isascii.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:27:10 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 16:03:33 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <ctype.h>

void	test_ft_isascii()
{
	printf("test ft_isascii\n");
	g_test_id = -1;
	while (g_test_id < 257)
	{
		int_comp(isascii(g_test_id), ft_isascii(g_test_id));
		g_test_id++;
	}
}
