#include "libft.h"

void				ft_list_push_back(t_list **begin_list, void *data)
{
	t_list			*new_list;

	if ((new_list = *begin_list) == NULL)
		*begin_list = ft_create_elem(data);
	else
	{
		while (new_list->next)
			new_list = new_list->next;
		new_list->next = ft_create_elem(data);
	}
}
