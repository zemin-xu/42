/*
** find the first occurrence of the byte 'c' in the string beginning
** at 'string'
**
** return a pointer to the located byte, or a null pointer if no match
*/

#include "libft.h"

char				*ft_strchr(const char *string, int c)
{
	char			*str;

	if (string == NULL)
		return (NULL);
	str = (char *)string;
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
