/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 16:38:35 by zexu              #+#    #+#             */
/*   Updated: 2019/06/24 17:14:20 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	int		i;
	int		flag;

	if ((flag = 0) == length)
		return (0);
	i = 0;
	while (i < length - 1)
	{
		if ((*f)(tab[i], tab[i + 1]) > 0)
		{
			if (flag == 0)
				flag = 1;
			else if (flag == -1)
				return (0);
		}
		else if ((*f)(tab[i], tab[i + 1]) < 0)
		{
			if (flag == 0)
				flag = -1;
			else if (flag == 1)
				return (0);
		}
		i++;
	}
	return (1);
}
