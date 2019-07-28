#include "libft.h"

void				ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list			*curr_list;

	if ((curr_list = begin_list) == NULL)
		return ;
	while (curr_list)
	{
		f(curr_list->data);
		curr_list = curr_list->next;
	}
}
