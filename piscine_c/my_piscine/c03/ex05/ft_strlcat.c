/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/10 17:23:27 by zexu              #+#    #+#             */
/*   Updated: 2019/06/11 18:42:08 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	unsigned int	nb;

	nb = 0;
	while (str[nb])
		nb++;
	return (nb);
}

unsigned int		ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	length;

	length = ft_strlen(dest);
	i = 0;
	while (src[i] && (i + 1 + length) < size)
	{
		dest[i + length] = src[i];
		i++;
	}
	dest[i + length] = '\0';
	if (size >= length)
		return (length + ft_strlen(src));
	else
		return (size + ft_strlen(src));
}
