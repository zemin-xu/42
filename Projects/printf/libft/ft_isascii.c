/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/09 10:16:59 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 10:17:21 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** return true if 'c' is a 7-bit unsigned char value that fits into
** the US/UK ASCII character set
*/

#include "libft.h"

int			ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
