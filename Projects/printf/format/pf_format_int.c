/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:09:50 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:10:00 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

int				pf_signed_int(va_list argp, t_pf **head_ref, t_pf *new)
{
	char		*str;
	int			tmp;

	if ((tmp = va_arg(argp, int)) < 0)
	{
		new->is_num_with_minus = 1;
		new->has_flag = 1;
	}
	if (!(str = ft_itoa(tmp)))
		return (-1);
	new->format_type = 'i';
	new->str_before = str;
	new->len = ft_strlen(str);
	return (t_pf_add(head_ref, new));
}

int				pf_unsigned_int(va_list argp, t_pf **head_ref, t_pf *new)
{
	char		*str;

	if (!(str = ft_uitoa(va_arg(argp, unsigned int))))
		return (-1);
	new->format_type = 'u';
	new->str_before = str;
	new->len = ft_strlen(str);
	return (t_pf_add(head_ref, new));
}

int				pf_hex(va_list argp, t_pf **head_ref, t_pf *new, int is_maj)
{
	char		*str;

	if (!(str = ft_hextoa(va_arg(argp, unsigned int), is_maj)))
		return (-1);
	new->format_type = 'u';
	new->str_before = str;
	new->len = ft_strlen(str);
	return (t_pf_add(head_ref, new));
}

int				pf_pointer(va_list argp, t_pf **head_ref, t_pf *new)
{
	char		*str;

	if (!(str = ft_ptoa(va_arg(argp, void *))))
		return (-1);
	new->format_type = 'p';
	new->str_before = str;
	new->has_flag = 1;
	new->len = ft_strlen(str);
	return (t_pf_add(head_ref, new));
}
