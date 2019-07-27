/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 22:42:03 by zexu              #+#    #+#             */
/*   Updated: 2019/06/13 10:10:49 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char					*ft_strncat(char *dest, char *src, unsigned int nb)
{
	unsigned int		i;
	unsigned int		length;

	i = 0;
	while (dest[i])
		i++;
	length = i;
	while (src[i - length] && (i - length) < nb)
	{
		dest[i] = src[i - length];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
