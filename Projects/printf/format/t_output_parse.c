#include "pf_format.h"

int t_output_flag(t_output *curr)
{
    int count;

    if (!curr)
        return (0);
    count = curr->length;
    if (!curr->flag->has_flag)
        ft_putstr_fd(curr->content, 1);
    else if (curr->flag->is_left_justified)
    {
        if (curr->flag->is_precised)
            count += pf_precise(curr, curr->flag->precise_num);
        ft_putstr_fd(curr->content, 1);
        count += t_output_pad(curr);
    }
    else
    {
        count += t_output_pad(curr);
        if (curr->flag->is_precised)
            count += pf_precise(curr, curr->flag->precise_num);
        ft_putstr_fd(curr->content, 1);
    }
    return (count);
}

int t_output_pad(t_output *curr)
{
    if (curr->flag->is_padded == 1)
        return (pf_pad(curr, curr->flag->pad_num, curr->flag->precise_num, ' '));
    else if (curr->flag->is_padded == 2)
        return (pf_pad(curr, curr->flag->pad_num, curr->flag->precise_num, '0'));
    else
        return (0); 
}

int t_output_read(t_output *head)
{
    int count;

    count = 0;
    t_output *current;

    if (!(current = head))
        return (0);
    count += t_output_flag(current);
    while ((current = current->next) != NULL)
        count += t_output_flag(current);
    return (count);
}