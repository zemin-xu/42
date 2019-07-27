/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/19 15:35:00 by zexu              #+#    #+#             */
/*   Updated: 2019/06/25 20:31:16 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int						ft_strlen(char *str)
{
	int					i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char					*ft_strcpy(char *str)
{
	int					i;
	char				*cpy;

	i = 0;
	cpy = malloc(sizeof(char) * (ft_strlen(str) + 1));
	while (str[i])
	{
		cpy[i] = str[i];
		i++;
	}
	cpy[i] = '\0';
	return (cpy);
}

struct s_stock_str		*ft_strs_to_tab(int ac, char **av)
{
	t_stock_str			*s;
	int					i;

	s = malloc(sizeof(t_stock_str) * (ac + 1));
	if (s == 0)
		return (0);
	i = 0;
	while (i < ac)
	{
		s[i].size = ft_strlen(av[i]);
		s[i].str = av[i];
		s[i].copy = ft_strcpy(av[i]);
		i++;
	}
	s[i].str = 0;
	return (s);
}
