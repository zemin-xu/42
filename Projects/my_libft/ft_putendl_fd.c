/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 16:56:13 by zexu              #+#    #+#             */
/*   Updated: 2019/10/07 16:56:16 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** output the string 's' to the file descriptor 'fd' followed by a '\n' 
*/

#include "libft.h"

void				ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}
