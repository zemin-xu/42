/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_strlen.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:39:18 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 15:20:49 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void	test_ft_strlen(void)
{
	printf("test ft_strlen\n");
	g_test_id = 1;//1
	int_comp(strlen(""), ft_strlen(""));
	g_test_id++;//2
	int_comp(strlen("46"), ft_strlen("46"));
}
