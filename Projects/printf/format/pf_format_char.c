/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format_char.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:11:57 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:11:59 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

int				pf_char(va_list argp, t_pf **res, t_pf *new)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = (char)va_arg(argp, int);
	*(str + 1) = '\0';
	new->format_type = 'c';
	new->str_before = str;
	new->len_before = 1;
	return (t_pf_add(res, new));
}

int				pf_str(va_list argp, t_pf **res, t_pf *new)
{
	char		*str;

	if (!(str = ft_strdup(va_arg(argp, char *))))
		return (-1);
	new->format_type = 's';
	new->str_before = str;
	new->len_before = ft_strlen(str);
	return (t_pf_add(res, new));
}

int				pf_percentage(t_pf **res, t_pf *new)
{
	char		*str;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = '%';
	*(str + 1) = '\0';
	new->format_type = '%';
	new->str_before = str;
	new->len_before = 1;
	return (t_pf_add(res, new));
}
