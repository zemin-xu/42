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

/*
int pf_pad(t_pf *str, size_t pad_len, size_t prec_len, char c)
{
	int rest;

	// exception
	if (*(str->content) == '-' && c == '0' && str->format_type == 'i')
	{
		write(1, "-", 1);
		ft_memmove(str->content, str->content + 1, str->length - 1);
		*(str->content + str->length - 1) = '\0';
	}
	if (prec_len == 0 || str->length > pad_len || str->length > prec_len)
	{
		if ((rest = pad_len - str->length) > 0)
		{
			while (--rest > -1)
				write(1, &c, 1);
		}
		return (pad_len > str->length ? pad_len - str->length : 0);
	}
	else
	{
		rest = (str->format_type == 's' ? (pad_len - str->length) : (pad_len - prec_len));
		if (rest > 0)
		{
			while (--rest > -1)
				write(1, &c, 1);
		}
		return (str->format_type == 's' ? (pad_len - str->length) : (pad_len - prec_len));
	}
}
*/
/*
int pf_precise(t_pf *str, size_t prec_len)
{
	int rest;
	int is_exception;

	// exception
	if (*(str->content) == '-' && str->format_type == 'i')
	{
		write(1, "-", 1);
		ft_memmove(str->content, str->content + 1, str->length - 1);
		*(str->content + str->length - 1) = '\0';
		is_exception = 1;
	}
	if (str->format_type == 's' && prec_len < str->length)
	{
		*(str->content + prec_len) = '\0';
		return (prec_len - str->length);
	}
	else if ((str->format_type == 'i' || str->format_type == 'u' ||
			  str->format_type == 'x' || str->format_type == 'X') &&
			 (rest = prec_len - str->length) > 0)
	{
		if (is_exception == 1)
			rest++;
		while (--rest > -1)
			write(1, "0", 1);
		return (prec_len - str->length + (is_exception == 1 ? 1 : 0));
	}
	else
		return (0);
}
*/

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
	size_t i;

	if (s == NULL || (str = (char *)malloc(str_len + pad_len + 1)) == NULL)
		return (NULL);
	i = -1;
	if (is_left)
	{
		inner_strncpy(str, s, str_len);
		while (++i < pad_len)
			*(str + str_len + i) = ' ';
	}
	else
	{
		while (++i < pad_len)
			*(str + i) = ' ';
		inner_strncpy(str + i, s, str_len);
	}
	*(str + str_len + i) = '\0';
	return (str);
}
