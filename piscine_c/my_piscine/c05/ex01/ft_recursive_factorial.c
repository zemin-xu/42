/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 19:11:02 by zexu              #+#    #+#             */
/*   Updated: 2019/06/12 20:33:04 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_recursive_factorial(int nb)
{
	int	res;

	if (nb < 0)
		return (0);
	else if (nb == 1 || nb == 0)
		return (1);
	else
	{
		res = nb * ft_recursive_factorial(nb - 1);
		return (res);
	}
}
