/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memcmp.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:32 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 14:28:03 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_memcmp(void)
{
	printf("test ft_memcmp\n");
	unsigned char array1[5] = {0, 100, 200, 255, 220};
	unsigned char array2[5] = {0, 100, 200, 255, 221};
	unsigned char array3[5] = {0, 100, 200, 254, 222};
	g_test_id = 1;//1
	int_comp(memcmp(array1, array2, 4), ft_memcmp(array1, array2, 4));	
	g_test_id++;//2
	int_comp(memcmp(array1, array3, 4), ft_memcmp(array1, array3, 4));	
	g_test_id++;//3
	int_comp(memcmp(array1, array3, 3), ft_memcmp(array1, array3, 3));	
}
