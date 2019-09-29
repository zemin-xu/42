/*
** copy the 'size' bytes at 'from' into the 'size' bytes in 'to',
** even the two blocks of space overlap
**
** ---- copy forward ----
** <to..........>
**         <from.........>
**
** ---- copy backward ----
** <from..........>
**         <to...........>
**
** return the value of 'to' 
*/

#include "libft.h"

void				*ft_memmove(void *to, const void *from, size_t size)
{
	size_t			i;
	unsigned char	*c_to;
	unsigned char	*c_from;

	c_to = (unsigned char *)to;
	c_from = (unsigned char *)from;
	if(c_to < c_from)
		return (ft_memcpy(to, from, size));
	else
	{
		i = size;
		while (i > 0)
		{
			*(c_to + i - 1) = *(c_from + i - 1);
			i--;
		}
		return (to);
	}
}
