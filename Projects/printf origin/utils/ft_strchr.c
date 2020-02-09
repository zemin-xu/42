/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:13:26 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:13:29 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** find the first occurrence of the byte 'c' in the string beginning
** at 'string'
**
** return a pointer to the located byte, or a null pointer if no match
*/

#include "pf_utils.h"

char				*ft_strchr(char const *string, int c)
{
	char			*str;

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
