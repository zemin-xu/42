/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/13 11:59:27 by zexu              #+#    #+#             */
/*   Updated: 2019/10/20 19:52:04 by zexu             ###   ########.fr       */
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
	

char				*ft_strtrim(char const *s1, char const *set)
{
	return (NULL);

}
