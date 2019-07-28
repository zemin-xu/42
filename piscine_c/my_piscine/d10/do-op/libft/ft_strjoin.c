#include "libft.h"

char				*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;

	if (s1 == NULL || s2 == NULL ||
			(str = (char *)malloc(ft_strlen(s1) + ft_strlen(s2) + 1)) == NULL)
		return (NULL);
	ft_strncpy(str, s1, ft_strlen(s1));
	ft_strncpy(str + ft_strlen(s1), s2, ft_strlen(s2));
	*(str + ft_strlen(s1) + ft_strlen(s2) + 1) = '\0';
	return (str);
}
