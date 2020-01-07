#include "pf_flag.h"

void pf_flag_read_num(t_flag *flag, char num)
{
    if (flag->is_precised)
        flag->precise_num = flag->precise_num * 10 + num - '0';
    else
        flag->pad_num = flag->pad_num * 10 + num - '0';
}