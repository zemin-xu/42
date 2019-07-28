#include "libft.h"

char				*ft_memchr(const char *s, int c, size_t n)
{
	size_t			i;

	i = 0;
	while (i < n)
	{
		if (*(s + i) == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}
