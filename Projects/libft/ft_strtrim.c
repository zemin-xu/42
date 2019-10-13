/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:59:27 by zexu              #+#    #+#             */
/*   Updated: 2019/10/13 14:20:42 by zexu             ###   ########.fr       */
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

static size_t		in_len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static int			in_ncmp(char const *s1, char const *s2, size_t size)
{
	while (size > 0)
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			size--;
		}
		else
			return (0);
	}
	return (1);
}

static void			in_ncpy(char *to, char *from, size_t size)
{
	size_t			i;

	i = 0;
	while (size)
	{
		*(to + i) = *(from + i);
		i++;
	}
}
	

char				*ft_strtrim(char const *s1, char const *set)
{
	char			*str;
	int				before;
	int				after;

	if (s1 == NULL)
		return (NULL);
	before = 0;
	after = in_len(s1);
	while (set && in_ncmp(s1 + before, set, in_len(set)))
		before += in_len(set);
	while (set && in_ncmp(s1 + after - in_len(set), set, in_len(set)))
		after -= in_len(set);
	if ((str = (char *)malloc(in_len(s1) - begin - after + 1)) == NULL)
		return (NULL);
	in_ncpy(str, s1 + begin, in_len(s1) - begin - after);
	*(str + in_len(s1)) = '\0';
	return (str);
}
