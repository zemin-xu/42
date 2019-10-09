#include "libft.h"

/*
 * return the Nth element of the list
 * begin_list is considered as 0th
 *
 */

t_list				*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	t_list			*curr_list;
	unsigned int	i;

	curr_list = begin_list;
	if (nbr == 0)
		return (curr_list);
	i = 0;
	while (i < nbr)
	{
		i++;
		curr_list = curr_list->next;
		if (i < nbr && curr_list == NULL)
			return (NULL);
	}
	return (curr_list);
}
