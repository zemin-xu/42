#include "pf_format.h"

t_output *pf_output_new(void *content, char type)
{
    t_output *list;

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

t_output *pf_output_last(t_output **head)
{
    t_output *current;

    if (!head)
        return (NULL);
    if (!(*head)->next)
        return (*head);
    current = *head;
    while (current->next)
        current = current->next;
    return (current);
}

int pf_output_add(t_output **head, t_output *new)
{
    t_output *last;

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

int     pf_output_free(t_output **head)
{
    t_output *current;
    t_output *next;

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
