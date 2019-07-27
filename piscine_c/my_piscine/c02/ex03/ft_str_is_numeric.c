/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_numeric.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/07 15:50:25 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 19:31:02 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_numeric(char *str)
{
	int	i;
	int	has_only_num;

	i = 0;
	has_only_num = 1;
	if (str[i] == '\0')
	{
		return (has_only_num);
	}
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			i++;
		else
		{
			has_only_num = 0;
			return (has_only_num);
		}
	}
	return (has_only_num);
}
