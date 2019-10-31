/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strncmp.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:40:02 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/09 15:36:47 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_strncmp(void)
{
	printf("test ft_strncmp\n");
	g_test_id = 1;//1
	int_comp(strncmp("42", "42", 2), ft_strncmp("42", "42", 2));
	g_test_id++;//2
	int_comp(strncmp("", "42", 2), ft_strncmp("", "42", 2));
	g_test_id++;//3
	int_comp(strncmp("42", "", 2), ft_strncmp("42", "", 2));
	g_test_id++;//4
	int_comp(strncmp("ace", "ac", 2), ft_strncmp("ace", "ac", 2));
	g_test_id++;//5
	int_comp(strncmp("ac", "ace", 2), ft_strncmp("ac", "ace", 2));
	g_test_id++;//6
	int_comp(strncmp("sdf123", "sdf456", 2), ft_strncmp("sdf123", "sdf456", 2));
	g_test_id++;//7
	int_comp(strncmp("abgk", "abif", 2), ft_strncmp("abgk", "abif", 2));
	g_test_id++;//8
	int_comp(strncmp("abgk", "abif", 3), ft_strncmp("abgk", "abif", 3));
	g_test_id++;//9
	int_comp(strncmp("abgk", "abif", 4), ft_strncmp("abgk", "abif", 4));
	g_test_id++;//10
	int_comp(strncmp("abgk", "abif", 0), ft_strncmp("abgk", "abif", 0));
	char str1[4] = {127, 1, 1, '\0'};
	char str2[4] = {-128, 1, 1, '\0'};
	g_test_id++;//11
	int_comp(strncmp(str1, str2, 4), ft_strncmp(str1, str2, 4));
	g_test_id++;//12
	int_comp(strncmp("\200", "\0", 1), ft_strncmp("\200", "\0", 1));
	g_test_id++;//13
	int_comp(strncmp("", "", 1), ft_strncmp("", "", 1));
}
