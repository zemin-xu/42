/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 10:48:22 by zexu              #+#    #+#             */
/*   Updated: 2019/06/27 16:41:34 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_is_prime(int nb)
{
	int	i;

	if (nb <= 1)
		return (0);
	i = 2;
	while (i < nb && i <= 46340)
	{
		if (nb % i == 0)
			return (0);
		i++;
	}
	return (1);
}

int		ft_find_next_prime(int nb)
{
	if (nb <= 2)
		return (2);
	if (ft_is_prime(nb))
		return (nb);
	if (nb % 2 == 0)
		nb++;
	while (ft_is_prime(nb) == 0)
	{
		nb += 2;
	}
	return (nb);
}
