/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 15:39:27 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 20:21:54 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_printable(char *str)
{
	int	i;
	int	is_printable;

	i = 0;
	is_printable = 1;
	if (str[i] == '\0')
		return (is_printable);
	while (str[i])
	{
		if (str[i] >= ' ' && str[i] <= '~')
			i++;
		else
		{
			is_printable = 0;
			return (is_printable);
		}
	}
	return (is_printable);
}
