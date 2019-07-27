/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/24 21:24:27 by zexu              #+#    #+#             */
/*   Updated: 2019/06/26 23:28:17 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "bsq.h"

char		**store_map(int n, int fd, int size)
{
	char	**res;
	char	buffer[size + 1];
	int		data;
	int		i;
	int		line;
	int		j;

	if((res = malloc(sizeof(*res) * n)) == NULL)
		return (NULL);
	i = 0;
	while (i < n)
	{
		res[i] = malloc(sizeof(char) * n);
		i++;
	}
	free(res);
	i = 0;
	line = 0;
	data = read(fd, buffer, size);
	while (data != 0)
	{
		while (i < size)
		{
			j = 0;
			while (line > 0 && buffer[i] != '\n')
			{
				res[line - 1][j] = buffer[i];	
				j++;
				i++;
			}
			if (buffer[i] == '\n')
			{
				line++;
			}
			i++;
		}
		data--;
	}
	return (res);
}

void		print_error()
{
	write(1, "map error\n",10);
}


int			main(int argc, char **argv)
{
	(void) argc;
	int	max[3] = {0, 1, 1};
	int current[3] = {0,1,1};

	int n;
	int	*pre_line;
	int	*cur_line;
	int	x;
	int	y;
	int		fd;
	char	**map;
	int *p_size;	
	int	*p_res = malloc(sizeof(int) * 5);
	p_size = malloc(sizeof(int));
	fd = open(argv[1], O_RDONLY);
	n = count_n(argv[1], p_size);	
	p_res[0] = *p_size;
	p_res[1] = n;
	map= malloc(sizeof(char *) *(n));
	map = init_map(fd, *p_size, n);
	close(fd);
	if((pre_line = malloc(sizeof(int) * n)) == NULL)
		return (0);
	if((cur_line= malloc(sizeof(int) * n)) == NULL)
		return (0);
	y = 1;
	x = 0;
	while (x < n)
	{
		pre_line[x] = 0;
		x++;
	}
	while (y < n + 1)
	{
		trans_line(map[y-1], cur_line, n); 
		x = 1;
		while (x < n + 1)
		{

			if ( x== n)
				cur_line[x] = 0;
			if(cur_line[x] != 0)
			{
				cur_line[x] = min(cur_line[x - 1], pre_line [x - 1], pre_line[x]) + 1;
				pass_value(current,  x, y, cur_line[x]);
				if (max[0] < cur_line[x])
					pass_max(max, current);
			}
			else
			{
				pass_value(current, x , y, 0);
			}
			x++;
		}
		pass_line(cur_line, pre_line, n);
		y++;	
	}
	p_res[2] = max[0];
	p_res[3] = max[1];
	p_res[4] = max[2];
	print_res(p_res, map);
	return (0);
}
