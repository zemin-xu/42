/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:24:54 by zexu              #+#    #+#             */
/*   Updated: 2019/10/20 16:56:58 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** find the first occurrence of the byte 'c' in the string beginning
** at 'string'
**
** return a pointer to the located byte, or a null pointer if no match
*/

#include "libft.h"

char				*ft_strchr(const char *string, int c)
{
	char			*str;

	if (string == NULL)
		return (NULL);
	str = (char *)string;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	else
		return (NULL);
}
