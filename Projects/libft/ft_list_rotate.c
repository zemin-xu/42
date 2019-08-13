#include "libft.h"

 /*
 ** shift up all elements in a list by 1
 ** the first element becomes the last one
 */

void				ft_list_rotate(t_list **begin_list)
{
	t_list			*last_list;

	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	last_list = ft_list_last(*begin_list);
	last_list->next = *begin_list;
	*begin_list = (*begin_list)->next;
	last_list->next->next = NULL;
}
