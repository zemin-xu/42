/*
 ** Add an item to the beginning of the list = pushing to the list
 ** 	- create a new item and set its value
 ** 	- link the new item to point to the head of the list
 ** 	- set the head of the list to be our new item
 **
 ** 	Since we use a function to do this operation, we want to be able
 ** 	to modify the head variable. To do this, we must pass a pointer to the 
 ** 	pointer variable (a double pointer) so we will be able to modify the 
 ** 	pointer itself.
 */

#include "ft_list.h"

void				ft_list_push_front(t_list **begin_list, void *data)
{
	t_list			*new_list;

	if ((new_list = malloc(sizeof(t_list))) == NULL)
		new_list = ft_create_elem(data);
	else
	{
		new_list->data = data;
		new_list->next = *begin_list;
		*begin_list = new_list;
	}
}
