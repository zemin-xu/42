#include "libft.h"

char				*ft_strmapi(char *s, char (*f)(unsigned int, char))
{
	size_t			len;
	char			*str;
	size_t			i;

	i = 0;
	len = ft_strlen(s);
	if ((str = (char *)malloc(len + 1)) == NULL)
		return (NULL);
	ft_strcpy(str, s);
	while (i < len)
	{
		*(str + i) = f((unsigned int)i, *(str + i));
		i++;
	}
	return (str);
}
