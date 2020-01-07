#include "pf_flag.h"

t_flag              *t_flag_init(void)
{
    t_flag          *new;

    if (!(new = (t_flag *)malloc(sizeof(t_flag))))
        return (NULL);

    new->has_flag = 0;
    new->is_left_justified = 0;
    new->is_padded_zero = 0;
    new->is_precised = 0;
    new->pad_num = 0;
    new->precise_num = -1;
    return (new);
}

void                t_flag_free(t_flag *flag)
{
    free(flag);
}