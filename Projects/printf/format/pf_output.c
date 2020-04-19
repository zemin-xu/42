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

t_pf				*t_pf_init(void *content, char type)
{
	t_pf			*list;

	if (!(list = (t_pf *)malloc(sizeof(t_pf))))
		return (NULL);
	list->format_type = type;
	list->str_before = content;
	list->len_before = ft_strlen(content);

	list->has_flag = 0;
	list->is_left_justified = 0;
	list->pad_num = -1;
	list->precise_num = -1;

	list->length = ft_strlen(content);
	list->next = NULL;
	return (list);
}

t_pf				*t_pf_last(t_pf *head)
{
	t_pf			*current;

	if (!head)
		return (NULL);
	if (!(head->next))
		return (head);
	current = head;
	while (current->next)
		current = current->next;
	return (current);
}

int						t_pf_add(t_pf **head_ref, t_pf *new)
{
	t_pf			*last;

	if (!head_ref || !new)
		return (-1);
	if (!(*head_ref))
		*head_ref = new;
	else
	{
		last = t_pf_last(*head_ref);
		last->next = new;
	}
	return (0);
}

int						t_pf_free(t_pf **head_ref)
{
	t_pf			*current;
	t_pf			*next;

	if (!head_ref || !(current = *head_ref))
		return (-1);
	while (current->next)
	{
		next = current->next;
		free(current->str_before);
		free(current);
		current = next;
	}
	free(current->str_before);
	free(current);
	head_ref = NULL;
	return (0);
}
