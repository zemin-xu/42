/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memset.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:36:43 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 14:43:59 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_memset(void)
{
	printf("test ft_memset\n");
	char	str1[6] = "Hello";
	char	str2[6] = "Hello";
	g_test_id = 1; //1
	str_comp(memset(str1, 'b', 3), ft_memset(str2, 'b', 3));
	unsigned char array1[6] = {0, 78, 127, 128, 200, 255};
	unsigned char array2[6] = {0, 78, 127, 128, 200, 255};
	g_test_id++;//2
	mem_comp(memset(array1, 149, 3), ft_memset(array2, 149, 3), 6);
}
