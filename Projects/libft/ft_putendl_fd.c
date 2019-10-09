/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:56:13 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 13:19:47 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** output the string 's' to the file descriptor 'fd' followed by a '\n'
*/

#include "libft.h"

static void			inner_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void				ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		inner_putchar_fd(*s, fd);
		s++;
	}
	inner_putchar_fd('\n', fd);
}
