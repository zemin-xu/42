/*
** allocate and return a new-created memory area
**
** the memory allocated is initialize to 0. If the allocation fails,
** the function returns NULL
*/
#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;
	
	if ((mem = malloc(size)) == NULL)
		return (NULL);
	else
		return (ft_memset(mem, 0, size));
}
