#include "libft.h"

void				*ft_memalloc(size_t size)
{
	void			*mem;
	
	if ((mem = malloc(size)) == NULL)
		return (NULL);
	else
		return (ft_memset(mem, 0, size));
}
