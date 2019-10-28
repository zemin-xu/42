/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:59:27 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 13:16:19 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a copy of the string given as argument without the
** characters specified in the 'set' argument at the beginning and the end of
** the string
**
** return NULL if the allocation fails
*/

#include "libft.h"

static char			*in_cpy(char *to, const char *from, size_t size)
{
	size_t			i;

	i = 0;
	while (i < size)
	{
		*(to + i) = *(from + i);
		i++;
	}
	*(to + i) = '\0';
	return (to);
}

static size_t		in_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int			in_cmp(char s1, char const *set)
{
	size_t			i;

	i = 0;
	while (i < in_len(set))
	{
		if (s1 == set[i])
			return (1);
		i++;
	}
	return (0);
}

static char			*in_malloc(char const *s1, size_t size, int begin)
{
	char			*str;

	if ((str = (char *)malloc(sizeof(char) * (size + 1))) == NULL)
		return (NULL);
	return (in_cpy(str, (s1 + begin), size));
}

char				*ft_strtrim(char const *s1, char const *set)
{
	size_t			begin;
	size_t			i;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL || in_len(set) == 0)
		return (in_malloc(s1, in_len(s1), 0));
	i = 0;
	while (i < in_len(s1) && (in_cmp(*(s1 + i), set) == 1))
		i++;
	begin = i;
	i = 0;
	while (i < in_len(s1) && (in_cmp(*(s1 + in_len(s1) - 1 - i), set) == 1))
		i++;
	if (begin == in_len(s1))
		return (in_malloc(s1, 0, 0));
	else
		return (in_malloc(s1, in_len(s1) - begin - i, begin));
}
