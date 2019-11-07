/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/08 22:26:51 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 11:59:44 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** search 'haystack' for a substring 'needle', from the first byte to
** 'size' bytes at most
**
** return a pointer into the string 'haystack' that is the first byte
** of the substring, or a null pointer if no match
** if 'needle' is an empty string, the function returns 'haystack'
*/

#include "libft.h"

static int			compare(const char *haystack, const char *needle,
		size_t innersize)
{
	size_t			i;

	i = 0;
	while (*haystack && *needle && i < innersize)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
		i++;
		if (i == innersize)
			return (*needle == '\0');
	}
	return (*needle == '\0');
}

char				*ft_strnstr(const char *haystack, const char *needle,
		size_t size)
{
	size_t			i;

	i = 0;
	if (*needle == '\0')
		return ((char *)haystack);
	while (*haystack && i < size)
	{
		if ((*haystack == *needle) && compare(haystack, needle, size - i))
			return ((char *)haystack);
		haystack++;
		i++;
	}
	return (NULL);
}
