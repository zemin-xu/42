#include "libft.h"

char				*ft_strrchr(const char *s, int c)
{
	char			*str;
	size_t			len;

	str = (char *)s;
	len = ft_strlen(s);
	if (s == NULL)
		return (NULL);
	while (len > 0)
	{
		if (*(str + len) == c)
			return (str + len);
		len--;
	}
	if (*str == c)
		return (str);
	else
		return (NULL);
}
