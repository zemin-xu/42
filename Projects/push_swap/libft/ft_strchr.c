#include "libft.h"

char				*ft_strchr(const char *s, int c)
{
	char			*str;

	if (s == NULL)
		return (NULL);
	str = (char *)s;
	while (*str)
	{
		if (*str == c)
			return (str);
		str++;
	}
	if (*str == c)
		return (str);
	else
		return (NULL);
}
