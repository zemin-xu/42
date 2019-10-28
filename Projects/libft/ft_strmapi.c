/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 11:07:55 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 14:26:47 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t		inner_strlen(const char *s)
{
	size_t			i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char			*inner_strcpy(char *to, const char *from)
{
	size_t			i;

	i = 0;
	while (from[i])
	{
		to[i] = from[i];
		i++;
	}
	to[i] = from[i];
	return (to);
}

char				*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*str;
	size_t			i;

	if (s == NULL || f == NULL)
		return (NULL);
	i = 0;
	len = inner_strlen(s);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	inner_strcpy(str, s);
	while (i < len)
	{
		*(str + i) = f((unsigned int)i, *(str + i));
		i++;
	}
	return (str);
}
