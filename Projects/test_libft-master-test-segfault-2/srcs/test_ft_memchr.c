/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memchr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:33:12 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 13:56:32 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_memchr(void)
{
	printf("test ft_memchr\n");
	unsigned char array[4] = {0, 100, 200, 255};
	g_test_id = 1;//1
	ptr_comp(memchr(array, -14, 4), ft_memchr(array, -14, 4), 1);
	g_test_id++;//2
	ptr_comp(memchr(array, 0, 4), ft_memchr(array, 0, 4), 1);
	g_test_id++;//3
	ptr_comp(memchr(array, 100, 4), ft_memchr(array, 100, 4), 1);
	g_test_id++;//4
	ptr_comp(memchr(array, 0, 0), ft_memchr(array, 0, 0), 1);
	g_test_id++;//5
	ptr_comp(memchr(array, 128, 4), ft_memchr(array, 128, 4), 1);
	g_test_id++;//6
	ptr_comp(memchr(array, 255, 4), ft_memchr(array, 255, 4), 1);
}
