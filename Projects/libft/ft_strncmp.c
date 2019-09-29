#include "libft.h"

int			ft_strncmp(const char *s1, const char *s2, size_t size)
{
	size_t	i;

	if (size == 0)
		return (0);
	i = 0;
	while (*(s1 + i) && *(s1 + i) == *(s2 + i))
	{
		if (i < size - 1)
			i++;
		else 
			return (0);	
	}
	return (*((unsigned char *)s1 + i) - *((unsigned char *)s2 + i));
}
