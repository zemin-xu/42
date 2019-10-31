/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strtrim.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:41:02 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/12 15:11:58 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	test_ft_strtrim(void)
{
	printf("test ft_strtrim\n");
	g_test_id = 1;//1
	str_comp("Hello !", ft_strtrim("Hello !", ""));
	g_test_id++;//2
	str_comp("ello !", ft_strtrim("Hello !", "H"));
	g_test_id++;//3
	str_comp("Hello ", ft_strtrim("Hello !", "!"));
	g_test_id++;//4
	str_comp("ello", ft_strtrim("Hello !", "Hl !"));
	g_test_id++;//5
	str_comp("", ft_strtrim("", ""));
	g_test_id++;//6
	str_comp("", ft_strtrim("", "H"));
}
