/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:01:16 by zexu              #+#    #+#             */
/*   Updated: 2019/11/03 16:41:55 by zexu             ###   ########.fr       */
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

char					*strdup_with_ends(char *s, size_t start, size_t end)
{
	size_t				i;
	char				*str;

	if (start >= end)
		return (NULL);
	i = 0;
	if ((str = malloc(end - start + 1)) == NULL)
		return (NULL);
	while (i < end - start)
	{
		if (start == 0)
			*(str + i) = *(s + start + i);
		else
			if (i < end - start - 1)
				*(str + i) = *(s + start + i + 1);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}


int						get_next_line(int fd, char **line)
{
	static t_gnl_list	*tmp;
	char				*buffer;
	int					read_value;
	size_t				end;
	size_t				start;
	char				*res;

	gnl_push_back(&tmp, gnl_new(strdup_with_ends("here I am", 0, 9), 10, 0));
	gnl_push_back(&tmp, gnl_new(strdup_with_ends("here you do", 0, 11), fd, 0));
	gnl_push_back(&tmp, gnl_new(strdup_with_ends("wish you", 0, 8), fd, 0));
	gnl_push_back(&tmp, gnl_new(strdup_with_ends("here he can", 0, 11), 10, 0));

	// already lines in list
	if ((gnl_search(tmp, fd)) == 2)
	{
		res = gnl_fetch(&tmp, fd);
	while (tmp)
	{
		printf("%s\n", tmp->content);
		tmp = tmp->next;
	}
	}

	// no result or incomplet result in list
	else
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if ((read_value = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			end = 0;
			start = 0;
			while (end < read_value)
			{
				// meet an '\n'
				if (*(buffer + end) == '\n')
				{
					// retrive content
					gnl_push_back(&tmp, gnl_new(strdup_with_ends(buffer,
									start, end), fd, 0));
					if (gnl_search(tmp, fd) == 1)
						res = gnl_fetch(&tmp, fd);  
					start = end;

				}
				// meet an '\0' without '\n' before, program stop here
				else if (*(buffer + end) == '\0')
				{
					gnl_push_back(&tmp, gnl_new(strdup_with_ends(buffer,
									start, end), fd, 0));
					return (0);
				}
				end++;
			}
			// meet end of the buffer without '\n' nor '\0'
			gnl_push_back(&tmp, gnl_new(strdup_with_ends(buffer, start, end), fd, 1));
			// if res == NULL, recursive
		}

		if (res != NULL)
			free(res);
		free(buffer);
	}
	return (0);
}

int						main()
{
	char				*newline;
	int					fd;

	fd = open("test.txt", O_RDONLY); 
	get_next_line(fd, &newline);
	
	return (0);
}
