#include "pf_flag.h"

void pf_flag_read_char(t_flag *flag, char num)
{
    if (flag->is_precised)
        flag->precise_num = flag->precise_num * 10 + num - '0';
    else
    {
        flag->is_padded = 1;
        flag->pad_num = flag->pad_num * 10 + num - '0';
    }
}

void pf_flag_read_int(t_flag *flag, int num)
{
    if (flag->is_precised)
        flag->precise_num = num;
    else
    {
        flag->is_padded = 1;
        flag->pad_num = num;
    }
}