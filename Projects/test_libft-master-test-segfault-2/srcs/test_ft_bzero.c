/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_bzero.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 15:15:02 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 12:42:37 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <strings.h>

void	test_ft_bzero(void)
{
	printf("test ft_bzero\n");
	char	str1[6] = "Hello";
	char	str2[6] = "Hello";
	bzero(str1, 3);
	ft_bzero(str2, 3);
	g_test_id = 1; //1
	str_comp(str1, str2);
	g_test_id++; //2
	str_comp(str1 + 1, str2 + 1);
	g_test_id++; //3
	str_comp(str1 + 2, str2 + 2);
	g_test_id++; //4
	str_comp(str1 + 3, str2 + 3);

}
