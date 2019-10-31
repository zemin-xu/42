/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strrchr.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:40:43 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/09 11:17:50 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_strrchr(void)
{
	printf("test ft_strrchr\n");
	char	str[9] = {-128, -65, 1, 'a', 12, 127, -65, 12, '\0'};
	g_test_id = 1;//1
	ptr_comp(strrchr(str, 13), ft_strrchr(str, 13), 1);
	g_test_id++;//2
	ptr_comp(strrchr(str, -128), ft_strrchr(str, -128), 1);
	g_test_id++;//3
	ptr_comp(strrchr(str, -65), ft_strrchr(str, -65), 1);
	g_test_id++;//4
	ptr_comp(strrchr(str, 0), ft_strrchr(str, 0), 1);
	g_test_id++;//5
	ptr_comp(strrchr(str, 'a'), ft_strrchr(str, 'a'), 1);
	g_test_id++;//6
	ptr_comp(strrchr(str, 12), ft_strrchr(str, 12), 1);
	g_test_id++;//7
	ptr_comp(strrchr(str, 127), ft_strrchr(str, 127), 1);
	g_test_id++;//8
	ptr_comp(strrchr(str, '\0'), ft_strrchr(str, '\0'), 1);
}
