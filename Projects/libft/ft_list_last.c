#include "libft.h"

t_list				*ft_list_last(t_list *begin_list)
{
	t_list			*curr_list;
	if ((curr_list = begin_list) == NULL)
		return (NULL);
	while (curr_list->next)
		curr_list = curr_list->next;
	return (curr_list);
}
