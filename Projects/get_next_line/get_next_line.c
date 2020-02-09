/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:01:16 by zexu              #+#    #+#             */
/*   Updated: 2020/02/09 13:25:56 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
 ** Return a line read from a file descriptor without the newline character.
 **
 ** Return '1' if a line has been read;
 ** return '0' if EOF has been reached;
 ** return '-1' if an error happens.
 */

/*
 ** ssize_t		read(int fd, void *buf, size_t count);
 **
 ** read() attempts to read up to 'count' bytes from file descriptor 'fd'
 ** into the buffer starting at 'buf'.
 **
 ** If 'count' is zero, read() may detect the errors. If it does not check for
 ** errors, it returns zero and has no other effects.
 **
 ** On success, the number of bytes read is returned (zero indicates EOF),
 ** and the file position is advanced by this number.
 */

/*
 ** File descriptor is integer that uniquely identifies an open file of process.
 */

#include "get_next_line.h"

char					*ft_strncpy(char *to, const char *from, size_t size)
{
	unsigned int		i;

	i = 0;
	while (from[i] && i < size)
	{
		to[i] = from[i];
		i++;
	}
	while (i < size)
	{
		to[i] = '\0';
		i++;
	}
	return (to);
}

char					*ft_strjoin(char const *s1, char const *s2)
{
	char				*str;
	size_t				len1;
	size_t				len2;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len1 = 0;
	len2 = 0;
	while (s1[len1])
		len1++;
	while (s2[len2])
		len2++;
	if ((str = (char *)malloc(len1 + len2 + 1)) == NULL)
		return (NULL);
	ft_strncpy(str, s1, len1);
	ft_strncpy(str + len1, s2, len2);
	*(str + len1 + len2) = '\0';
	free((void *)s1);
	free((void *)s2);
	return (str);
}

char					*gnl_strdup(char *s, size_t start, size_t end)
{
	size_t				i;
	size_t				j;
	char				*str;

	if (start >= end && end != 0)
		return (NULL);
	i = 0;
	j = 0;
	if ((str = malloc(end - start + 1)) == NULL)
		return (NULL);
	while (i < end - start)
	{
		if (*(s + start + i) != '\n')
		{
			*(str + j) = *(s + start + i);
			j++;
		}
		i++;
	}
	*(str + j) = '\0';
	return (str);

}

void					get_next_line_2(t_gnl_list **tmp, int fd, char *buffer,
		int read_value)
{
	size_t				begin;
	size_t				end;

	end = 0;
	begin = 0;
	while ((int)end < read_value)
	{
		if (*(buffer + end) == '\n')
		{
			gnl_push_back(tmp,
					gnl_new(tmp, gnl_strdup(buffer, begin, end), fd, 0));
			begin = end;
		}
		end++;
	}
	gnl_push_back(tmp, gnl_new(tmp, gnl_strdup(buffer, begin, end), fd, 1));
}

int						get_next_line(int fd, char **line)
{
	static t_gnl_list	*tmp;
	char				buffer[BUFFER_SIZE];
	int					read_value;

	if (fd < 0 || line == NULL || BUFFER_SIZE < 1)
		return (-1);
	while ((gnl_search(tmp, fd)) != 2)
	{
		if ((read_value = read(fd, buffer, BUFFER_SIZE)) < 0)
			return (-1);
		else if (read_value == 0)
		{
			gnl_push_back(&tmp, gnl_new(&tmp, gnl_strdup("", 0, 0), fd, 0));
			*line = gnl_fetch(&tmp, fd);
			free(tmp);
			return (0);
		}
		else if (read_value > 0)
			get_next_line_2(&tmp, fd, buffer, read_value);
	}
	*line = gnl_fetch(&tmp, fd);
	return (1);
}

#include <stdio.h>
#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **argv)
{
	/*
	   char	*line;
	   int		fd;

	   ac++;
	   fd = open(argv[1], O_RDONLY);
	   while ((get_next_line(fd, &line) && line))
	   {
	   printf("%s\n", line);
	   free(line);
	   line = NULL;
	   }
	   return (0);
	   */

	char *line;
	int fd[2];
	fd[0] = open(argv[1], O_RDONLY);
	fd[1] = open(argv[2], O_RDONLY);

	int i;
	i = 0;
	ac++;
	while ((get_next_line(fd[i % 2], &line) && line))
	{
		printf("%s\n", line);
		free(line);
		line = NULL;
		i++;
	}

}

