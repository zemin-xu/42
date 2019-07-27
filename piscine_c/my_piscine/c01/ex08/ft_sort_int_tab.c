/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/06 13:10:39 by zexu              #+#    #+#             */
/*   Updated: 2019/06/06 15:27:25 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

void	ft_sort_int_tab(int *tab, int size)
{
	int i;
	int has_sorted;

	while (1)
	{
		has_sorted = 0;
		i = 0;
		while (i < size - 1)
		{
			if (*(tab + i) > *(tab + i + 1))
			{
				ft_swap((tab + i), (tab + i + 1));
				has_sorted = 1;
			}
			i++;
		}
		if (has_sorted == 0)
			break ;
	}
}
