/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_uppercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:30:53 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 19:49:42 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_str_is_uppercase(char *str)
{
	int		i;
	int		all_uppercase;

	i = 0;
	all_uppercase = 1;
	if (str[i] == '\0')
	{
		return (all_uppercase);
	}
	while (str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
		{
			i++;
			continue ;
		}
		else
		{
			all_uppercase = 0;
			return (all_uppercase);
		}
	}
	return (all_uppercase);
}
