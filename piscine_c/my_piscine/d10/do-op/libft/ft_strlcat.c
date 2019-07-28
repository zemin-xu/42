#include "libft.h"

size_t		ft_strlcat(char *dst, const char *src, size_t n)
{
	size_t	len;
	size_t	i;

	len = ft_strlen(dst);
	if (len + 1 >= n)
		*(dst + n - 1) = '\0';
	else
	{
		i = 0;
		while (*(src + i) && i < n - len - 1)
		{
			*(dst + len + i) = *(src + i);
			i++;
		}
		*(dst + len + i) = '\0';
	}
	return (len + ft_strlen(src));
}
