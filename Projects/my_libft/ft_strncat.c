/*
** append 'size' bytes from 'from' to the end of 'to'
**
** 'from' need not be null-terminated
**
** a single null byte is also appended to 'to', so the total allocated
** size of 'to' must be at least 'size + 1" bytes longer than its 
** initial length
*/

#include "libft.h"

char		*ft_strncat(char *to, const char *from, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(to);
	i = 0;
	while (*(from + i) && i < size)
	{
		*(to + len + i) = *(from + i);
		i++;
	}
	*(to + len + i) = '\0';
	return (to);
}
