/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 17:01:16 by zexu              #+#    #+#             */
/*   Updated: 2019/11/02 23:46:32 by zexu             ###   ########.fr       */
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


t_tmp_list				*tmp_list_new(char *content, int fd)
{
	t_tmp_list			*list;

	if ((list = (t_tmp_list *)malloc(sizeof(t_tmp_list))) == NULL)
		return (NULL);
	list->content = content;
	list->fd = fd;
	list->next = NULL;
	return (list);
}

void					tmp_list_push_back(t_tmp_list **head, t_tmp_list *new)
{
	t_tmp_list          *list_last;

	if (head && new)
	{
		if (*head == NULL)
			*head = new;
		else
		{
			list_last = *head;
			while (list_last->next)
				list_last = list_last->next;
			list_last->next = new;
		}
	}
}

char					*search_list(t_tmp_list *head, int fd)
{
	t_tmp_list			*curr_list;

	if (head->fd == fd)
		return (head->content);
	curr_list = head;
	while (curr_list->next)
	{
		if (curr_list->fd == fd)
			return (curr_list->content);
		curr_list = curr_list->next;
	}
	if (curr_list->fd == fd)
		return (curr_list->content);
	else
		return (NULL);

}

char					*ft_strdup_with_ends(char *s, size_t start, size_t end)
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
			*(str + i) = *(s + start + i + 1);

		i++;
	}
	*(str + i) = '\0';
	return (str);
}

int						get_next_line(int fd, char **line)
{
	static t_tmp_list	*tmp;
	char				*buffer;
	int					read_value;
	size_t				end;
	size_t				start;
	char				*res;

	if (tmp != NULL)
	{
		if ((res = search_list(tmp, fd)) == NULL)
		{

		}
	}
	else
	{
		buffer = (char *)malloc(sizeof(char) * BUFFER_SIZE);
		if ((read_value = read(fd, buffer, BUFFER_SIZE)) > 0)
		{
			end = 0;
			start = 0;
			while (end < read_value)
			{
				if (*(buffer + end) == '\n')
				{
					tmp_list_push_back(&tmp, tmp_list_new(ft_strdup_with_ends(buffer,
									start, end), fd));
					start = end;
				}
				else if (*(buffer + end) == '\0')
				{

				}
				end++;
			}
		}
		
		t_tmp_list *curr = tmp;
		while (curr)
		{
			printf("%s", curr->content); 
			curr = curr->next;
		}
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
