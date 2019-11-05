/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:01:16 by zexu              #+#    #+#             */
/*   Updated: 2019/11/05 17:36:05 by zexu             ###   ########.fr       */
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

	// already lines in list
	if ((gnl_search(tmp, fd)) == 2)
	{
		*line = gnl_fetch(&tmp, fd);
		return (1);
	}
	else
	{
		// no result or incomplet result in list
		if ((buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE)) == NULL)
			return (-1);

		read_value = read(fd, buffer, BUFFER_SIZE);
		printf("%d\n", read_value);

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
			// meet end of the buffer without '\n' nor '\0'
			gnl_push_back(&tmp, gnl_new(&tmp,
						strdup_with_ends(buffer, start, end), fd, 1));
			/*
			   printf("-----------------------start-----------------\n");
			   while (tmp)
			   {
			   printf("%s\n", tmp->content);
			   tmp = tmp->next;
			   }
			   printf("-----------------------end-------------------\n");
			   */

			printf("outer");
			get_next_line(fd, line);
			free(buffer);
		}
		return (1);
	}
}

int						main()
{
	char				*newline;
	int					fd;
	int					ret;

	/*
	t_gnl_list			*tmp;
	gnl_push_back(&tmp, gnl_new(&tmp,
				strdup_with_ends("dddd gg tt", 0, 10), 3, 0));
	gnl_push_back(&tmp, gnl_new(&tmp,
				strdup_with_ends("what is it", 0, 10), 3, 1));
	gnl_push_back(&tmp, gnl_new(&tmp,
				strdup_with_ends("who are you", 0, 11), 3, 1));
	printf("-----------------------start-----------------\n");
	printf("%s\n", tmp->content);
	printf("%s\n", tmp->next->content);
	printf("-----------------------end-------------------\n");
	*/


	fd = open("test.txt", O_RDONLY); 
	printf("\nreturn value: %d",ret = get_next_line(fd, &newline));
	return (0);
}
