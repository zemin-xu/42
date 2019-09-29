#include "libft.h"

char				*ft_strdup(const char *s)
{
	size_t			i;
	char			*str;

	if (s == NULL || (str = malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = 0;
	while (i < ft_strlen(s))
	{
		*(str + i) = *(s + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
