/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_memmove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:34:04 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/17 15:41:19 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>

void	test_ft_memmove(void)
{
	printf("test ft_memmove\n");
	char	str1[27] = "abcdefghijklmnopqrstuvwxyz";
	char	ft_str1[27] = "abcdefghijklmnopqrstuvwxyz";
	g_test_id = 1; //1
	str_comp(memmove(str1 + 3, str1, 15), ft_memmove(ft_str1 + 3, ft_str1, 15));
	g_test_id++;//2
	str_comp(str1, ft_str1);
}
