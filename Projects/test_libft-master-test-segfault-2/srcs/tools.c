/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:51:53 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 14:42:35 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

void str_comp(char *str1, char *str2)
{
	int res;

	if (str1 && str2)
		res = strcmp(str1, str2);
	else if (str1 == NULL && str2 == NULL)
		res = 0;
	else
		res = 1;
	if (res)
	{
		printf("  test %.2d \033[1;31mKO\033[0m\n", g_test_id);
		printf("  should be: \"%s\"\n", str1);
		printf("        was: \"%s\"\n", str2);
	}
}

void int_comp(int nb1, int nb2)
{
	if (nb1 != nb2)
	{
		printf("  test %.2d \033[1;31mKO\033[0m\n", g_test_id);
		printf("  should be: \"%d\"\n", nb1);
		printf("        was: \"%d\"\n", nb2);
	}
}


void ptr_comp( void *nb1, void *nb2, int equal)
{
	if ((nb1 != nb2 && equal) || (nb1 == nb2 && !equal))
	{
		printf("  test %.2d \033[1;31mKO\033[0m\n", g_test_id);
		printf("  should be: \"%p\"\n", nb1);
		printf("        was: \"%p\"\n", nb2);
	}
}

void mem_comp(void *ptr1, void *ptr2, int size)
{
	int res = memcmp(ptr1, ptr2, size);
	if (res != 0)
	{
		printf("  test %.2d \033[1;31mKO\033[0m\n", g_test_id);
		printf("  should be: \"%d\"\n", 0);
		printf("        was: \"%d\"\n", res);
	}
}
