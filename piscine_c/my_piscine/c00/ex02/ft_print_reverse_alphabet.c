/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_reverse_alphabet.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 18:57:32 by zexu              #+#    #+#             */
/*   Updated: 2019/06/08 18:57:48 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void		ft_print_reverse_alphabet(void)
{
	int		i;
	char	ch;

	i = 0;
	ch = 'z';
	while (i < 26)
	{
		write(1, &ch, 1);
		i++;
		ch--;
	}
}