#include "pf_format.h"
void				pf_flag_parse_s(t_pf *list)
{
	size_t		str_len;
	size_t		pad_len;

	str_len = ft_strlen(list->str_before);
	if (list->precise_num != -1 && (int)str_len > list->precise_num)
		str_len = list->precise_num;
	if (list->pad_num != -1 && (int)str_len < list->pad_num)
		pad_len = list->pad_num - str_len;
	if (list->is_left_justified)
	{
		list->str_after = pf_join_with_pad_space(list->str_before, str_len, pad_len, 1);
	}
	else
	{
		list->str_after = pf_join_with_pad_space(list->str_before, str_len, pad_len, 0);
	}
	list->len = ft_strlen(list->str_after);
}