/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_substr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:41:29 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/12 12:48:36 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_substr(void)
{
	printf("test ft_substr\n");
	g_test_id = 1;//1
	str_comp("", ft_substr("Hello", 0, 0));
	g_test_id++;//2
	str_comp("H", ft_substr("Hello", 0, 1));
	g_test_id++;//3
	str_comp("Hello", ft_substr("Hello", 0, 5));
	g_test_id++;//4
	str_comp("Hello", ft_substr("Hello", 0, 6));
	g_test_id++;//5
	str_comp("Hello", ft_substr("Hello", 0, 7));
	g_test_id++;//6
	str_comp("ello", ft_substr("Hello", 1, 7));
	g_test_id++;//7
	str_comp("llo", ft_substr("Hello", 2, 7));
	g_test_id++;//8
	str_comp("lo", ft_substr("Hello", 3, 7));
	g_test_id++;//9
	str_comp("o", ft_substr("Hello", 4, 7));
	g_test_id++;//10
	str_comp("", ft_substr("Hello", 5, 7));
	g_test_id++;//11
	str_comp("", ft_substr("", 0, 1));
	g_test_id++;//12
	str_comp("", ft_substr("", 1, 1));
	g_test_id++;//13
	str_comp("", ft_substr("Hi", 4, 10));
}
