/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 18:58:15 by zexu              #+#    #+#             */
/*   Updated: 2019/06/26 18:48:19 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char		*same_charset(char *src, char *charset)
{
	int		i;
	int		j;

	i = 0;
	while (src[i])
	{
		j = 0;
		while (charset[j])
		{
			if (src[i] == charset[j])
				src[i] = charset[0];	
			j++;
		}
		i++;
	}
	return (src);
}

int			counter(char *str, char *charset)
{
	int		flag;
	int		i;
	int		j;
	int		k;

	str = same_charset(str, charset);
	i = 0;
	j = 0;
	k = 0;
	flag = 1;
	while (str[i])
	{
		if (str[i] == charset[0])
		{
			flag = 0;
			j = 0;
		}
		else
			flag = 1;
		if (flag == 1)
		{
			if(j == 0)
				k++;
			j++;
		}
		i++;
	}	
	return (k);
}

char		*ft_strncat(char *src, char *dest,int n)
{
	int		i;
	int		length;
	i = 0;
	while (dest[i])
		i++;
	length = i;
	while (i - length < n)
	{
		dest[i] = src[i - length];
		i++;
	}	
	return (dest);
}

char		**ft_split(char *str, char *charset)
{
	int		i;
	int		j;
	char	*temp;	
	char	**res;
	i = 0;
	while (str[i])
		i++;
	temp = malloc(sizeof(char) * (i + 1));
	temp[0] = '\0';
	/*j
	ft_strncat(str, temp, i + 1);
	temp = same_charset(temp, charset); 
	res = malloc(sizeof(char *) * counter(temp, charset));	
	j = -1;
	while (j < counter(temp, charset))
		res[++j] = malloc(sizeof(char) * (i + 1));
	
	int k;
	int flag;
	i = 0;
	j = 0;
	k = 0;
	flag = 1;
	while (temp[i])
	{
		if (temp[i] == charset[0])
		{
			flag = 0;
		}
		else
			flag = 1;
		if (flag == 1)
		{
			if(j == 0)
			{
				res[k][j] = '\0';	
				j = 0;
				k++;
			}
			j++;
		}
		i++;
	}
	*/
	return (res);
}

#include <stdio.h>
int			main(int ac, char **av)
{
	(void) ac;
	char	**res;
	res = ft_split(av[1], av[2]);
	/*
	for (int i = 0; res[i]; i++)
	{
		printf("%s", res[i]);
	}
	*/
	return 0;
}
