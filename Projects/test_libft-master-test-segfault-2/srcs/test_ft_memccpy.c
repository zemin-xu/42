/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memccpy.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:16:02 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/09 15:50:26 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_memccpy(void)
{
	printf("test ft_memccpy\n");
	unsigned char arr1[5] = {0, 50, 129, 255, 145};
	unsigned char arr2[5] = {1, 5, 130, 254, 144};
	unsigned char ft_arr1[5] = {0, 50, 129, 255, 145};
	unsigned char ft_arr2[5] = {1, 5, 130, 254, 144};
	g_test_id = 1; //1
	ptr_comp(memccpy(arr1, arr2, 144, 4), ft_memccpy(ft_arr1, ft_arr2, 144, 4), 1);
	g_test_id++;//2
	mem_comp(arr1, ft_arr1, 5);
	unsigned char arr3[5] = {0, 50, 129, 255, 145};
	unsigned char arr4[5] = {1, 5, 130, 254, 144};
	unsigned char ft_arr3[5] = {0, 50, 129, 255, 145};
	unsigned char ft_arr4[5] = {1, 5, 130, 254, 144};
	memccpy(arr3, arr4, 130, 4);
	g_test_id++;//3
	ptr_comp(ft_arr3 + 3, ft_memccpy(ft_arr3, ft_arr4, 130, 4), 1);
	g_test_id++;//4
	mem_comp(arr3, ft_arr3, 5);
}
