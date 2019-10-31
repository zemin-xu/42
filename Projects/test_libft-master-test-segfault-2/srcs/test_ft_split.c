/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_ft_split.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 12:36:28 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/12 16:20:12 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static void	test(char *s, char c)
{
	int i = 0;
	char **array = ft_split(s, c);
	printf("%d split '%s' with '%c'. Result pointer is '%p'.\n", g_test_id, s, c, array);
	while (array[i])
	{
		printf("'%s'\n", array[i]);
		i++;
	}
	g_test_id++;
}

void	test_ft_split(void)
{
	printf("test ft_split\n");
	g_test_id = 1;
	test("Hello !", 0);
	test("Hello !", 'l');
	test("Hello !", 'H');
	test("Hello !", '!');
	test("I am a 42 student", ' ');
	test("   I am a 42 student      ", ' ');
	test("  I am a 42 student", ' ');
	test("I am a 42 student  ", ' ');
	test("", ' ');
	test("", 0);
}
