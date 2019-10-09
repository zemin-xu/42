#include "libft.h"

 /*
 ** shift down all elements in a list by 1
 ** the last element becomes the first one
 */

void				ft_list_rotate_reverse(t_list **begin_list)
{
	t_list			*last_list;
	int				size;

	if (*begin_list == NULL || (*begin_list)->next == NULL)
		return ;
	size = ft_list_size(*begin_list);
	last_list = ft_list_at(*begin_list, size - 1);
	ft_list_at(*begin_list, size - 2)->next = NULL;
	last_list->next = *begin_list;
	*begin_list = last_list;
}
