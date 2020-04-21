#include "pf_format.h"

void				pf_flag_parse_i(t_pf *list)
{
	size_t		str_len;
	size_t		pad_len;
	char		*tmp;

	str_len = ft_strlen(list->str_before);
	pad_len = 0;
	tmp = list->str_before;
	if (list->precise_num != -1 && list->precise_num > (int)str_len)
		tmp = pf_join_prec_with_num(list->str_before, str_len, 
									list->precise_num - str_len, list->is_num_with_minus);
	if (list->pad_num != -1 && (int)ft_strlen(tmp) < list->pad_num)
		pad_len = list->pad_num - ft_strlen(tmp);
	if (list->is_left_justified)
		list->str_after = pf_join_with_pad_space(tmp, ft_strlen(tmp), pad_len, 1);
	else
		list->str_after = pf_join_with_pad_space(tmp, ft_strlen(tmp), pad_len, 0);
	list->len = ft_strlen(list->str_after);
}

