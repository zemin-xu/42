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

int				pf_signed_int(va_list argp, t_pf **res)
{
	char		*str;
	t_pf	*new;

	if (!(str = ft_itoa(va_arg(argp, int))))
		return (-1);
	if (!(new = t_pf_init(str, 'i')))
		return (-1);
	return (t_pf_add(res, new));
}

int				pf_unsigned_int(va_list argp, t_pf **res)
{
	char		*str;
	t_pf	*new;

	if (!(str = ft_uitoa(va_arg(argp, unsigned int))))
		return (-1);
	if (!(new = t_pf_init(str, 'u')))
		return (-1);
	return (t_pf_add(res, new));
}

int				pf_hex(va_list argp, t_pf **res, int is_maj)
{
	char		*str;
	t_pf	*new;

	if (!(str = ft_hextoa(va_arg(argp, unsigned int), is_maj)))
		return (-1);
	if (!(new = t_pf_init(str, 'x')))
		return (-1);
	return (t_pf_add(res, new));
}

int				pf_pointer(va_list argp, t_pf **res)
{
	char		*str;
	t_pf	*new;

	if (!(str = ft_ptoa(va_arg(argp, void *))))
		return (-1);
	if (!(new = t_pf_init(str, 'p')))
		return (-1);
	return (t_pf_add(res, new));
}
