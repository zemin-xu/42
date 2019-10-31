/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcpy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:47:32 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/07 16:04:18 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_memcpy(void)
{
	printf("test ft_memcpy\n");
	char	str1[4] = "llo";
	char	str2[6] = "Heppi";
	char	ft_str1[4] = "llo";
	char	ft_str2[6] = "Heppi";
	g_test_id = 1; //1
	str_comp(memcpy(str2 + 2, str1, 3), ft_memcpy(ft_str2 + 2, ft_str1, 3));
}
