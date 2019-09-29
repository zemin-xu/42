/*
** copy 'size' bytes from the object beginning at 'from' into the object
** beginning at 'to'
**
** the behaviour of this function is undefined if the two arrays 'to'
** and 'from' overlap
**
** return the value of 'to'
*/

#include "libft.h"

void				*ft_memcpy(void *to, const void *from, size_t size)
{
	size_t			i;
	unsigned char	*c_to;
	unsigned char	*c_from;

	i = 0;
	c_to = (unsigned char *)to;
	c_from = (unsigned char *)from;
	while (i < size)
	{
		*(c_to + i) = *(c_from + i);	
		i++;
	}
	return (to);
}
