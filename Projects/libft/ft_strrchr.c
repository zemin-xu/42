/*
** like 'strchr' but search backwards from the end of the 'string'
**
** return a pointer to the located byte, or a null pointer if no match
*/

#include "libft.h"

char				*ft_strrchr(const char *string, int c)
{
	char			*str;
	size_t			len;

	str = (char *)string;
	len = ft_strlen(string);
	if (string == NULL)
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
