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

int pf_pad(t_output *str, size_t pad_len, size_t prec_len, char c)
{
    int rest;

    if (prec_len == 0 || str->length > pad_len)
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
        if ((rest = pad_len - prec_len) > 0)
        {
            while (--rest > -1)
                write(1, &c, 1);
        }
        return (pad_len - prec_len);
    }
}

int pf_precise(t_output *str, size_t prec_len)
{
    int rest;
    char c;

    c = '0';
    if (str->format_type == 's' && prec_len < str->length)
    {
        *(str->content + prec_len) = '\0';
        return (prec_len - str->length);
    }
    else if ((str->format_type == 'i' || str->format_type == 'u' ||
              str->format_type == 'x' || str->format_type == 'X') &&
             (rest = prec_len - str->length) > 0)
    {
        while (--rest > -1)
            write(1, &c, 1);
        return (prec_len - str->length);
    }
    else
        return (0);
}
