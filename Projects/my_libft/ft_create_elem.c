#include "libft.h"

t_list				*ft_create_elem(void *data)
{
	t_list			*list;

	if ((list = (t_list *)malloc(sizeof(t_list))) == NULL)
		return (NULL);
	list->data = data;
	list->next = NULL;
	return (list);
}
