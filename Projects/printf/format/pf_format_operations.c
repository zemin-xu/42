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
