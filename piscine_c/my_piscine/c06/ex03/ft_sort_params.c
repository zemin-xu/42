/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 17:07:22 by zexu              #+#    #+#             */
/*   Updated: 2019/06/17 21:49:49 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_putchar(char c)
{
	write(1, &c, 1);
}

void		ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void		ft_sort_char_tab(char *str, int size)
{
	int		i;
	int		has_swap;
	int		tmp;

	while (1)
	{
		has_swap = 0;
		i = 0;
		while (i < size - 1)
		{
			if (str[i] > str[i + 1])
			{
				tmp = str[i];
				str[i] = str[i + 1];
				str[i + 1] = tmp;
				has_swap = 1;
			}
			i++;
		}
		if (has_swap == 0)
			break ;
	}
}

int			main(int argc, char *argv[])
{
	int		i;

	i = argc;
	while (i > 1)
	{
		ft_sort_char_tab(argv[argc - i + 1], ft_strlen(argv[argc - i + 1]));
		ft_putstr(argv[argc - i + 1]);
		ft_putchar('\n');
		i--;
	}
	return (0);
}
