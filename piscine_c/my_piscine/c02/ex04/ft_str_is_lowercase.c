/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 16:30:53 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 19:35:08 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int			ft_str_is_lowercase(char *str)
{
	int		i;
	int		all_lowercase;

	i = 0;
	all_lowercase = 1;
	if (str[i] == '\0')
	{
		return (all_lowercase);
	}
	while (str[i])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			i++;
			continue ;
		}
		else
		{
			all_lowercase = 0;
			return (all_lowercase);
		}
	}
	return (all_lowercase);
}
