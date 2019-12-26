/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 13:20:17 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 15:13:11 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	inner_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	long	tmp;

	tmp = (long)n;
	if (tmp < 0)
	{
		inner_putchar_fd('-', fd);
		tmp *= -1;
	}
	if (tmp >= 10)
	{
		ft_putnbr_fd(tmp / 10, fd);
		ft_putnbr_fd(tmp % 10, fd);
	}
	else
		inner_putchar_fd(tmp + '0', fd);
}
