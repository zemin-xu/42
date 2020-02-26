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

int				pf_char(va_list argp, t_pf **list)
{
	char		*str;
	t_pf		*new;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = (char)va_arg(argp, int);
	*(str + 1) = '\0';
	if (!(new = pf_new(str, 'c')))
		return (-1);
	return (pf_output_add(list, new));
}

int				pf_str(va_list argp, t_pf **list)
{
	char		*str;
	t_pf		*new;

	if (!(str = ft_strdup(va_arg(argp, char *))))
		return (-1);
	if (!(new = pf_output_new(str, 's')))
		return (-1);
	return (pf_output_add(list, new));
}

/* perhaps here I should change the type into C, to test %% with flags */
int				pf_percentage(t_pf **list)
{
	char		*str;
	t_pf		*new;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = '%';
	*(str + 1) = '\0';
	if (!(new = pf_output_new(str, '%')))
		return (-1);
	return (pf_output_add(list, new));
}
