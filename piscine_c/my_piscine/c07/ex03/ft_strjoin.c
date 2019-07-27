/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 12:20:50 by zexu              #+#    #+#             */
/*   Updated: 2019/06/26 19:10:04 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int			size_strs(char **strs, int size)
{
	int		i;
	int		nb;

	i = 0;
	nb = 0;
	while (i < size)
	{
		nb += ft_strlen(strs[i]);
		i++;
	}
	return (nb);
}

char		*ft_strcpy(char *dest, char *src)
{
	int		i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = src[i];
	return (dest);
}

char		*ft_strjoin(int size, char **strs, char *sep)
{
	int		i[2];
	char	*res;

	res = malloc(sizeof(*res));
	if (size == (res[0] = '\0'))
		return (res);
	else
	{
		i[0] = -1;
		i[1] = 0;
		if ((res = malloc(sizeof(*res) * (ft_strlen(sep) *
							(size - 1) + size_strs(strs, size) + 1))) == NULL)
			return (NULL);
		while (++i[0] < size - 1)
		{
			ft_strcpy((res + i[1]), strs[i[0]]);
			i[1] += ft_strlen(strs[i[0]]);
			ft_strcpy((res + i[1]), sep);
			i[1] += ft_strlen(sep);
		}
		ft_strcpy((res + i[1]), strs[i[0]]);
		i[1] = ft_strlen(strs[i[0]]) + i[1];
		res[i[1]] = '\0';
		return (res);
	}
}
