/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_output.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:10:36 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:10:37 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

t_pf				*pf_output_new(void *content, char type)
{
	t_pf			*list;

	if (!(list = (t_pf *)malloc(sizeof(t_pf))))
		return (NULL);
	list->content = content;
	list->format_type = type;
	list->length = ft_strlen(content);
	if (!(list->flag = t_flag_init()))
		return (NULL);
	list->next = NULL;
	return (list);
}

t_pf				*pf_output_last(t_pf **head)
{
	t_pf			*current;

	if (!head)
		return (NULL);
	if (!(*head)->next)
		return (*head);
	current = *head;
	while (current->next)
		current = current->next;
	return (current);
}

int						pf_output_add(t_pf **head, t_pf *new)
{
	t_pf			*last;

	if (!head || !new)
		return (-1);
	if (!(*head))
		*head = new;
	else
	{
		last = pf_output_last(head);
		last->next = new;
	}
	return (0);
}

int						pf_output_free(t_pf **head)
{
	t_pf			*current;
	t_pf			*next;

	if (!head || !(current = *head))
		return (-1);
	while (current->next)
	{
		next = current->next;
		free(current->content);
		t_flag_free(current->flag);
		free(current);
		current = next;
	}
	free(current->content);
	t_flag_free(current->flag);
	free(current);
	head = NULL;
	return (0);
}
