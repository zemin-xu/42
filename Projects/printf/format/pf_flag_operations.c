/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_operations.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:11:10 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:11:14 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

static char *inner_strncpy(char *to, const char *from, size_t size)
{
	unsigned int i;

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

char	*pf_join_with_pad_zero(char const *s, size_t str_len, size_t pad_len, int is_left)
{
	char *str;
	size_t i;

	if (s == NULL || (str = (char *)malloc(str_len + pad_len + 1)) == NULL)
		return (NULL);
	i = -1;
	if (is_left)
	{
		inner_strncpy(str, s, str_len);
		while (++i < pad_len)
			*(str + str_len + i) = '0';
	}
	else
	{
		while (++i < pad_len)
			*(str + i) = '0';
		inner_strncpy(str + i, s, str_len);
	}
	*(str + str_len + i) = '\0';
	return (str);
}


char	*pf_join_with_pad_space(char const *s, size_t str_len, size_t pad_len, int is_left)
{
	char *str;
	int	 i;

	if (s == NULL || (str = (char *)malloc(str_len + pad_len + 1)) == NULL)
		return (NULL);
	i = -1;
	if (is_left)
	{
		inner_strncpy(str, s, str_len);
		while (++i < (int)pad_len)
			*(str + str_len + i) = ' ';
	}
	else
	{
		while (++i < (int)pad_len)
			*(str + i) = ' ';
		inner_strncpy(str + i, s, str_len);
	}
	*(str + str_len + i) = '\0';
	return (str);
}

char	*pf_join_prec_with_num(char const *s, size_t num_len, size_t prec_len, int is_minus)
{
	char *str;
	int	 i;

	if (s == NULL || (str = (char *)malloc(num_len + prec_len + (is_minus ? 1 : 0) + 1)) == NULL)
		return (NULL);
	i = 0;
	if (is_minus)
	{
		*(str) = '-';
		i++;
	}
	while (i < (int)prec_len + (is_minus ? 1 : 0))
	{
		*(str + i) = '0';
		i++;
	}
	inner_strncpy(str + i, s, num_len);
	*(str + num_len + i) = '\0';
	return (str);	
}
