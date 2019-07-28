#include "libft.h"

int				ft_list_size(t_list *begin_list)
{
	t_list		*curr_list;
	int			i;

	if ((curr_list = begin_list) == NULL)
		return (0);
	i = 0;
	while (curr_list)
	{
		curr_list = curr_list->next;
		i++;
	}
	return (i);
}
