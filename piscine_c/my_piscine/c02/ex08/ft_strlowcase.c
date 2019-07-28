/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlowcase.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:05:55 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 21:25:29 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strlowcase(char *str)
{
	int		i;
	int		space;

	space = 'a' - 'A';
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += space;
		i++;
	}
	return (str);
}