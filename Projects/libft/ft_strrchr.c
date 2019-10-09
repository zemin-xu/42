/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:21:10 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 10:27:30 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** like 'strchr' but search backwards from the end of the 'string'
**
** return a pointer to the located byte, or a null pointer if no match
*/

#include "libft.h"

static size_t		len(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char				*ft_strrchr(const char *string, int c)
{
	char			*str;
	size_t			length;

	str = (char *)string;
	length = len(string);
	if (string == NULL)
		return (NULL);
	while (length > 0)
	{
		if (*(str + length) == c)
			return (str + length);
		length--;
	}
	if (*str == c)
		return (str);
	else
		return (NULL);
}
