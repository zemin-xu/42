#include "pf_format.h"

void t_output_flag(t_output *curr)
{
    if (!curr)
        return;
    if (!curr->flag->has_flag)
    {
        ft_putstr_fd(curr->content, 1);
        return;
    }
    if (curr->flag->is_left_justified)
    {
        if (curr->flag->is_precised)
            pf_precise(curr, curr->flag->precise_num);
        ft_putstr_fd(curr->content, 1);
        t_output_pad(curr);
    }
    else
    {
        t_output_pad(curr);
        if (curr->flag->is_precised)
            pf_precise(curr, curr->flag->precise_num);
        ft_putstr_fd(curr->content, 1);
    }
}

void t_output_pad(t_output *curr)
{
    if (curr->flag->is_padded == 1)
        pf_pad(curr, curr->flag->pad_num, ' ');
    else if (curr->flag->is_padded == 2)
        pf_pad(curr, curr->flag->pad_num, '0');
}

void t_output_read(t_output *head)
{
    t_output *current;

    if (!(current = head))
        return;
    t_output_flag(current);
    while ((current = current->next) != NULL)
        t_output_flag(current);
}