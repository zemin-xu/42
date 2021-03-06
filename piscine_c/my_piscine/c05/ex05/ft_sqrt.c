/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 22:10:57 by zexu              #+#    #+#             */
/*   Updated: 2019/06/27 15:48:16 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int	a;

	if (nb <= 0)
		return (0);
	a = 1;
	while (a * a < nb && a <= 46340)
		a++;
	if (a * a == nb)
		return (a);
	else
		return (0);
}
