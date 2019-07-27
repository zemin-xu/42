/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:40:31 by zexu              #+#    #+#             */
/*   Updated: 2019/06/11 18:44:30 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strcat(char *dest, char *src)
{
	int		i;
	int		length;

	i = 0;
	while (dest[i])
		i++;
	length = i;
	while (src[i - length])
	{
		dest[i] = src[i - length];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
