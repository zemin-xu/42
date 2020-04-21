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
	char		tmp;

	if (!(tmp = (char)va_arg(argp, int)))
		return (-1);
	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = tmp;
	*(str + 1) = '\0';
	new->format_type = 'c';
	new->str_before = str;
	new->len = ft_strlen(str);
	return (t_pf_add(res, new));
}

int				pf_str(va_list argp, t_pf **res, t_pf *new)
{
	char		*str;
	char		*tmp;

	if (!(tmp = va_arg(argp, char *)))
		tmp = "(null)";
	if (!(str = ft_strdup(tmp)))
		return (-1);
	new->format_type = 's';
	new->str_before = str;
	new->len = ft_strlen(str);
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
	new->len = ft_strlen(str);
	return (t_pf_add(res, new));
}
