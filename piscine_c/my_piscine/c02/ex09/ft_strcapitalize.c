/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/08 20:28:40 by zexu              #+#    #+#             */
/*   Updated: 2019/06/09 21:34:34 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char		*ft_strlowcase(char *str)
{
	int		i;
	int		space;

	space = 'a' - 'A';
	i = 0;
	while (str[i])
	{
		if (str[i] <= 'Z' && str[i] >= 'A')
			str[i] += space;
		i++;
	}
	return (str);
}

char		*ft_strcapitalize(char *str)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	ft_strlowcase(str);
	while (str[i] != '\0')
	{
		if (str[i] <= 'z' && str[i] >= 'a')
		{
			if (flag == 1)
			{
				str[i] = str[i] - 32;
				flag = 0;
			}
		}
		else if ((str[i] >= '0' && str[i] <= '9') || (str[i] <= 'z'
					&& str[i] >= 'a') || (str[i] >= 'A' && str[i] <= 'Z'))
			flag = 0;
		else
			flag = 1;
		i++;
	}
	return (str);
}
