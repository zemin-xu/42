/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:16:31 by zexu              #+#    #+#             */
/*   Updated: 2019/10/28 14:27:33 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_utils.h"

static void	inner_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putstr_fd(char *s, int fd)
{
	int		i;

	if (s == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		inner_putchar_fd(s[i], fd);
		i++;
	}
}

void		ft_putstr_fd_c_null(char *s, int fd, size_t len)
{
	size_t	i;

	i = 0;
	if (s == NULL)
		return ;
	while (i < len)
	{
		inner_putchar_fd(*(s + i), fd);
		i++;
	}
}
