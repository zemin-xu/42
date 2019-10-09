/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:10:13 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 14:06:35 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a new-created concatenation ending with '\0'
**
** return NULL if the allocation fails
*/

#include "libft.h"

static size_t		inner_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char			*inner_strncpy(char *to, const char *from, size_t size)
{
	unsigned int	i;

	i = 0;
	while (from[i] && i < size)
	{
		to[i] = from[i];
		i++;
	}
	while (i < size)
	{
		to[i] = '\0';
		i++;
	}
	return (to);
}

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	if (s1 == NULL || s2 == NULL ||
			(str = (char *)malloc(inner_strlen(s1) + inner_strlen(s2) + 1))
			== NULL)
		return (NULL);
	inner_strncpy(str, s1, inner_strlen(s1));
	inner_strncpy(str + inner_strlen(s1), s2, inner_strlen(s2));
	*(str + inner_strlen(s1) + inner_strlen(s2)) = '\0';
	return (str);
}
