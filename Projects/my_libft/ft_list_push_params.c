#include "libft.h"

t_list				*ft_list_push_params(int ac, char **av)
{
	t_list			*head;
	int				i;

	if (ac < 2)
		return (NULL);
	i = 1;
	while (i < ac)
	{
		ft_list_push_front(&head, (void *)av[i]);
		i++;
	}
	return (head);
}
