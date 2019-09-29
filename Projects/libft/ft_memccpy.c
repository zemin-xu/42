/*
** copy no more than 'size' bytes from 'from' to 'to', stopping if a byte
** matching 'c' is found
**
** the behaviour of this function is undefined if the two arrays 'to'
** and 'from' overlap
**
** return the value of a pointer into 'to' 1 byte past where 'c' was
** copied, or a null pointer if no byte matching
*/

#include "libft.h"

void				*ft_memccpy(void *to, const void *from, 
								int c, size_t size)
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
		if (*(c_from + i) == (unsigned char)c)
			return (to + i + 1);
		i++;
	}
	return (NULL);
}
