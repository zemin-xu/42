/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/12 21:44:32 by zexu              #+#    #+#             */
/*   Updated: 2019/06/12 22:10:43 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_fibonacci(int index)
{
	int	res;

	res = 0;
	if (index < 0)
		return (-1);
	else if (index == 0)
		return (res = 0);
	else if (index == 1)
		return (res = 1);
	else
		res = ft_fibonacci(index - 1) + ft_fibonacci(index - 2);
	return (res);
}
