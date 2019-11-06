/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:01:16 by zexu              #+#    #+#             */
/*   Updated: 2019/11/05 23:18:13 by zexu             ###   ########.fr       */
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
#include <stdio.h>

static size_t		ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static char			*inner_strncpy(char *to, const char *from, size_t size)
{
	unsigned int	i;

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

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	if (s1 == NULL || s2 == NULL || (str = (char *)malloc(ft_strlen(s1) +
					ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	inner_strncpy(str, s1, ft_strlen(s1));
	inner_strncpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	*(str + ft_strlen(s1) + ft_strlen(s2)) = '\0';
	return (str);
}

char					*strdup_with_ends(char *s, size_t start, size_t end)
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

int						get_next_line(int fd, char **line)
{
	static t_gnl_list	*tmp;
	char				*buffer;
	int					read_value;
	size_t				end;
	size_t				start;

	t_gnl_list			*test;
	test = tmp;

	printf("-----------------------start-----------------\n");
	while (test)
	{
		printf("\n");
		printf("%s\n", test->content);
		printf("%d\n", test->fd);
		printf("%d\n", test->incomplete);
		printf("\n");
		test= test->next;
	}
	printf("-----------------------end-------------------\n");
	
	// already lines in list
	if ((gnl_search(tmp, fd)) == 2)
	{
		*line = gnl_fetch(&tmp, fd);
		return (1);
	}

	// no result or incomplet result in list
	if ((buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
		return (-1);

	read_value = read(fd, buffer, BUFFER_SIZE);

	//printf("%d\n",read_value);
	if (read_value == 0)
		return (0);

	if (read_value > 0)
	{
		end = 0;
		start = 0;
		while (end < read_value)
		{
			// meet an '\n'
			if (*(buffer + end) == '\n')
			{
				// retrive content
				gnl_push_back(&tmp, gnl_new(&tmp,
							strdup_with_ends(buffer, start, end), fd, 0));
				start = end;
			}
			// meet an '\0' without '\n' before, program stop here
			else if (*(buffer + end) == '\0')
			{
				gnl_push_back(&tmp, gnl_new(&tmp, 
							strdup_with_ends(buffer, start, end), fd, 0));
				return (0);
			}
			end++;
		}
			gnl_push_back(&tmp, gnl_new(&tmp,
					strdup_with_ends(buffer, start, end), fd, 1));
		get_next_line(fd, line);
	}
	free(buffer);
	return (1);
}

int						main()
{
	char				*newline;
	int					fd[2];
	int	i = 0;
	int j = 0;
	

	fd[0] = open("get_next_line_utils.c", O_RDONLY); 
	fd[1] = open("copy.txt", O_RDONLY); 
	if (fd[0] != -1 && fd[1] != -1)
	{

		while (i < 150)
		{
			j = get_next_line(fd[0], &newline);
//			printf("%d || %s\n", j, newline);
			i++;
		}
	}

	close(fd[0]);
	close(fd[1]);

	return (0);
}
