/*
** append the nul-terminated string 'from' to the end of 'to'
** at most 'size - strlen(to) - 1' bytes, nul-terminating the result
**
** return theinitial length of 'to' plus the length of 'from'
*/

#include "libft.h"

size_t		ft_strlcat(char *to, const char *from, size_t size)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(to);
	if (len + 1 >= size)
		*(to + size - 1) = '\0';
	else
	{
		i = 0;
		while (*(from + i) && i < size - len - 1)
		{
			*(to + len + i) = *(from + i);
			i++;
		}
		*(to + len + i) = '\0';
	}
	return (len + ft_strlen(from));
}
