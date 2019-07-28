#include "libft.h"

void				*ft_memset(void *b, int c, size_t len)
{
	char			*p;
	unsigned char	ch;
	size_t			i;

	ch = (unsigned char)c;
	p = (char *)b;
	if (p == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		*(p + i) = c;
		i++;
	}
	return (b);
}
