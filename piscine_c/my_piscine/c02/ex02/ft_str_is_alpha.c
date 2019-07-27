/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_alpha.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 14:15:01 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 19:28:42 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_alpha(char *str)
{
	int	i;
	int has_only_letters;

	i = 0;
	has_only_letters = 1;
	if (str[i] == '\0')
	{
		has_only_letters = 1;
		return (has_only_letters);
	}
	while (str[i])
	{
		if (str[i] <= 'z' && str[i] >= 'a')
			i++;
		else if (str[i] <= 'Z' && str[i] >= 'A')
			i++;
		else
		{
			has_only_letters = 0;
			return (has_only_letters);
		}
	}
	return (has_only_letters);
}
