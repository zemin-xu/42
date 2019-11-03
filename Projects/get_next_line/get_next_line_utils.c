/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:47:49 by zexu              #+#    #+#             */
/*   Updated: 2019/11/03 16:41:31 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>


t_gnl_list				*gnl_new(char *content, int fd, int incomplete)
{
	t_gnl_list			*list;

	if ((list = (t_gnl_list *)malloc(sizeof(t_gnl_list))) == NULL)
		return (NULL);
	list->content = content;
	list->fd = fd;
	list->incomplete = incomplete;
	list->next = NULL;
	return (list);
}

void					gnl_push_back(t_gnl_list **head, t_gnl_list *new)
{
	t_gnl_list			*list_last;

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

// 0: no res 1: res incomplete 2:res complete
int						gnl_search(t_gnl_list *head, int fd)
{
	t_gnl_list			*curr_list;

	curr_list = head;
	while (curr_list)
	{
		if (curr_list->fd == fd)
		{
			if (curr_list->incomplete == 1)
				return (1);
			else
				return (2);
		}
		curr_list = curr_list->next;
	}
	return (0);
}

char					*gnl_fetch(t_gnl_list **head, int fd)
{
	char				*tmp;
	t_gnl_list			*curr_list;
	size_t				i;

	curr_list = *head;
	while (curr_list)
	{
		if (curr_list-> fd == fd)
		{
			i = 0;
			while (*((curr_list->content) + i)) 
				i++;
			tmp = strdup_with_ends(curr_list->content, 0, i);	
			gnl_free_one(head, curr_list);
			return (tmp);
		}
		curr_list = curr_list->next;
	}
	return (NULL);
}

void				gnl_free_one(t_gnl_list **head, t_gnl_list *target)
{
	t_gnl_list		*pre_list;

	if (*head == target)
	{
		pre_list = *head;
		if ((*head)->next)
			*head = (*head)->next;
		else
			*head = NULL;
	}
	else
	{
		pre_list = *head;
		while (pre_list->next)
		{
			if (pre_list->next == target)
			{
				if (pre_list->next->next)
					pre_list->next = pre_list->next->next;
				else
					pre_list->next = NULL;
			}
			pre_list = pre_list->next;
		}
	}
	free(target->content);
	free(target);
}
