/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 10:10:54 by zexu              #+#    #+#             */
/*   Updated: 2019/06/21 10:52:10 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*ft_strdup(char *src)
{
	int		i;
	char	*res;

	i = 0;
	while (src[i])
		i++;
	if ((res = malloc((i + 1) * sizeof(*res))) == NULL)
		return (NULL);
	res[i + 1] = '\0';
	while (i >= 0)
	{
		res[i] = src[i];
		i--;
	}
	return (res);
}
