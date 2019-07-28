#include "libft.h"

char				*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*str;

	size_t			i;
	if (s == NULL || start > ft_strlen(s) || 
			(str = (char *)malloc(len + 1)) == NULL) 
		return (NULL);
	i = 0;
	while (i < len && *(s + start + i))
	{
		*(str + i) = *(s + start + i);
		i++;
	}
	*(str + i) = '\0';
	return (str);
}
