#include "pf_format.h"

t_output        *t_output_new(void *content, char type)
{
    t_output    *list; 

    if (!(list = (t_output *)malloc(sizeof(t_output))))
        return (NULL);
    list->content = content;
    list->format_type = type;
    list->length = ft_strlen(content);
    if (!(list->flag = t_flag_init()))
        return (NULL);
    list->next = NULL;
    return (list);
}

t_output        *t_output_last(t_output **head)
{
    t_output    *current;

    if (!(*head)->next)
        return (*head);
    current = *head;
    while (current->next)
        current = current->next;
    return (current);
}

void    	    t_output_add(t_output **head, t_output *new)
{
	t_output    *last;

	if (head && new)
	{
		if (*head == NULL)
			*head = new;
		else
		{
			last = t_output_last(head);
			last->next = new;
		}
	}
}

void            t_output_free(t_output **head)
{
    t_output    *current;
    t_output    *next;

    if (!(current = *head))
        return ;
    while (current->next)
    {
        next = current->next;
        free(current->content);
        free(current);
        current = next;
    }
    free(current->content);
    free(current);
    head = NULL;
}