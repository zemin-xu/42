#include "libft.h"

void				ft_list_remove_front(t_list **begin_list)
{
	t_list			*tmp_list;

	if (*begin_list == NULL)
		return ;
	else
	{
		tmp_list = *begin_list;
		if (tmp_list->next == NULL)
			*begin_list = NULL;
		else
			*begin_list = tmp_list->next;
		free(tmp_list);
	}
}
