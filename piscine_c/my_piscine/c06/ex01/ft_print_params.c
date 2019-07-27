/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_params.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/13 21:35:21 by zexu              #+#    #+#             */
/*   Updated: 2019/06/19 10:31:41 by zexu             ###   ########.fr       */
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

int			main(int argc, char *argv[])
{
	int		i;

	i = argc;
	while (i > 1)
	{
		ft_putstr(argv[argc - i + 1]);
		ft_putchar('\n');
		i--;
	}
	return (0);
}
