/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 15:51:49 by zexu              #+#    #+#             */
/*   Updated: 2019/06/13 14:28:45 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strstr(char *str, char *to_find)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((str[i] == 0 && to_find[i] == 0) || (str[i] && to_find[i] == 0))
		return (str);
	else if (str[i] == '\0' && to_find[i])
		return (0);
	while (str[i])
	{
		if (to_find[j] == '\0' && j != 0)
			return (&str[i - j]);
		if ((to_find[j] != '\0') && (str[i] == to_find[j]))
			j++;
		else if (str[i] != to_find[j])
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	return ((j != 0 && to_find[j] == '\0') ? &str[i - j] : 0);
}
