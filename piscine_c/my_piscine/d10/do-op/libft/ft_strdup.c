#include "libft.h"

char				*ft_strdup(const char *str)
{
	size_t			i;
	char			*s;

	if (str == NULL || (s = malloc(ft_strlen(str) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(str))
	{
		*(s + i) = *(str + i);
		i++;
	}
	*(s + i) = '\0';
	return (s);
}
