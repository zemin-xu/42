#include "libft.h"

char				*ft_strmap(char const *s, char (*f)(char))
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
		*(str + i) = f(*(str + i));
		i++;
	}
	return (str);
}
