/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ptang <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 20:54:53 by ptang             #+#    #+#             */
/*   Updated: 2019/06/26 23:21:53 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int		count_size(int fd, char *first_line)
{
	char	buffer;
	int		i;

	i = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (buffer != '.')
			first_line[i] = buffer;
		i++;
	}
	return (i);
}

int		count_n(char *file_name, int *p_size)
{
	int		n;
	char	*first_line;
	int		fd;
	first_line = malloc(sizeof(*first_line) * 1000);
	fd = open(file_name, O_RDONLY);
	*p_size = count_size(fd, first_line);
	n = ft_atoi(first_line);
	close(fd);
	free(first_line);
	return (n);
}

char	**init_map(int fd, int size, int n)
{
	char	**res;

	res = store_map(n, fd, size);
	return (res);
}
