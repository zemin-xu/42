/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 15:30:09 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 14:20:18 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return an array of strings ending with '\0', obtained by
** spliting 's' using the character 'c' as a delimiter
*/

#include "libft.h"

static size_t	inner_count(const char *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] != c && s[i] != '\0')
		i++;
	return (i);
}

static int		num_strings_1(char const *s, char c, size_t i, size_t j)
{
	int			num;
	int			flag;

	num = 1;
	flag = 0;
	while (i < inner_count(s, '\0') - j - 1)
	{
		if (*(s + i) == c && flag == 0)
		{
			flag = 1;
			num++;
		}
		else if (*(s + i) != c)
			flag = 0;
		i++;
	}
	return (num);
}

static int		num_strings_2(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (*(s + i) == c)
	{
		i++;
	}
	if (inner_count(s, '\0') == 0 || i == inner_count(s, '\0'))
		return (0);
	while (*(s + inner_count(s, '\0') - j - 1) == c)
	{
		j++;
	}
	return (num_strings_1(s, c, i, j));
}

char			**ft_split(char const *s, char c)
{
	char		**res;
	int			num;
	int			i;
	int			j;

	if (s == NULL)
		return (NULL);
	num = num_strings_2(s, c) + 1;
	i = -1;
	if ((res = malloc(sizeof(char *) * num)) == NULL)
		return (NULL);
	while (++i < num - 1)
	{
		j = 0;
		while (*s == c)
			s++;
		if ((res[i] = malloc(sizeof(char) * (inner_count(s, c) + 1))) == NULL)
			return (NULL);
		while (inner_count(s, c) > 0)
		{
			res[i][j++] = *s;
			s++;
		}
		res[i][j] = '\0';
	}
	*(res + i) = NULL;
	return (res);
}
