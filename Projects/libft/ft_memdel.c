/*
** take as a parameter the address of a memory area that needs to
** be freed, then puts the pointer to NULL
*/

#include "libft.h"

void				ft_memdel(void **ap)
{
	if (ap && *ap)
	{
		free(*ap);
		*ap = NULL;
	}
}
