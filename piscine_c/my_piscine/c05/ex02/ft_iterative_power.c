/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:59:55 by zexu              #+#    #+#             */
/*   Updated: 2019/06/12 21:41:52 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	while (power > 0)
	{
		res *= nb;
		power--;
	}
	return (res);
}
