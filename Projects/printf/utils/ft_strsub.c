/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:15:03 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:15:06 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** allocate and return a new-created substring from 's'
** the substring begins at index 'start' and is of size 'len'
**
** return NULL if the allocation fails
*/

#include "pf_utils.h"

static size_t		inner_strlen(char const *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;
	size_t			i;

	if (s == NULL)
		return (NULL);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i) && start < inner_strlen(s))
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
