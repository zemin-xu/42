/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:28:57 by zexu              #+#    #+#             */
/*   Updated: 2019/06/12 21:43:07 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_power(int nb, int power)
{
	int	res;

	res = 1;
	if (power < 0)
		return (0);
	else if (power == 0)
		return (1);
	else
		res = nb * ft_recursive_power(nb, power - 1);
	return (res);
}
