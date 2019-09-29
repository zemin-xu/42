/*
** copy the value of 'c' (converted to an unsigned char) into each of the
** first 'size' bytes of the object beginning at 'block'
**
** return the value of 'block'
*/

#include "libft.h"

void				*ft_memset(void *block, int c, size_t size)
{
	char			*p;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	p = (char *)block;
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < size)
	{
		*(p + i) = c;
		i++;
	}
	return (block);
}
