/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:58:15 by zexu              #+#    #+#             */
/*   Updated: 2019/06/27 18:00:00 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int			seperator(char c, char *charset)
{
	int		i;
	int		flag;

	i = 0;
	flag = 1;
	while (charset[i])
	{
		if (c == charset[i])
			return (flag);
		i++;
	}
	flag = 0;
	return (flag);
}

int			counter(char *str, char *charset)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && seperator(str[i], charset) == 1)
			i++;
		if (str[i] && seperator(str[i], charset) == 0)
		{
			count++;
			while (str[i] && seperator(str[i], charset) == 0)
				i++;
		}
	}
	return (count);
}

char		*mem_alloc(char *str, char *charset)
{
	char	*res;
	int		i;

	i = 0;
	while (str[i] && seperator(str[i], charset) == 0)
		i++;
	if ((res = malloc(sizeof(char) * (i + 1))) == NULL)
		return (NULL);
	i = 0;
	while (str[i] && seperator(str[i], charset) == 0)
	{
		res[i] = str[i];
		i++;
	}
	res[i] = 0;
	return (res);
}

char		**ft_split(char *str, char *charset)
{
	char	**res;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if ((res = malloc(sizeof(char *) * (counter(str, charset) + 1))) == NULL)
		return (0);
	while (str[i])
	{
		while (str[i] && seperator(str[i], charset) == 1)
			i++;
		if (str[i] && seperator(str[i], charset) == 0)
		{
			res[j] = mem_alloc(&str[i], charset);
			j++;
			while (str[i] && seperator(str[i], charset) == 0)
				i++;
		}
	}
	res[i] = NULL;
	return (res);
}
