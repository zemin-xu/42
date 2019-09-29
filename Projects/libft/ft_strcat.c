#include "libft.h"

char		*ft_strcat(char *to, const char *from)
{
	size_t	len;
	int		i;

	len = ft_strlen(to);
	i = 0;
	while (*(from + i))
	{
		*(to + len + i) = *(from + i);
		i++;
	}
	*(to + len + i) = '\0';
	return (to);
}
