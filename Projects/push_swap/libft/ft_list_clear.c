#include "libft.h"

void				ft_list_clear(t_list **begin_list)
{
	t_list			*curr_list;
	t_list			*next_list;

	curr_list = *begin_list;
	while (curr_list->next)
	{
		next_list = curr_list->next;
		free(curr_list);
		curr_list = next_list;
	}
	free(curr_list);
	*begin_list = NULL;
}
