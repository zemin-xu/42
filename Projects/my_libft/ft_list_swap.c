#include "libft.h"

 /*
 ** swap the first two elements on top of a list
 */


void				ft_list_swap(t_list **begin_list)
{
	t_list			*tmp_list;
	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	tmp_list = (*begin_list)->next;
	(*begin_list)->next = tmp_list->next;
	tmp_list->next = *begin_list;
	*begin_list = tmp_list;
}
