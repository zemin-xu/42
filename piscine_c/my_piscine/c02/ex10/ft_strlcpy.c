/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/09 10:49:01 by zexu              #+#    #+#             */
/*   Updated: 2019/06/10 15:33:16 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		ft_strlen(char *str)
{
	int				nb;

	nb = 0;
	while (str[nb])
		nb++;
	return (nb);
}

unsigned int		ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;

	if (size == 0)
		return (ft_strlen(src));
	else
	{
		i = 0;
		while (size > 1)
		{
			if ((dest[i] = src[i]) == '\0')
				break ;
			i++;
			size--;
		}
		if (size == 1)
			dest[i] = '\0';
		return (ft_strlen(src));
	}
}
