/*
** allocate and return a new-created string ending with '\0'
** 
** each character of the string is initialized at '\0'
*/

#include "libft.h"

char				*ft_strnew(size_t size)
{
	char			*str;
	if ((str = malloc(size)) == NULL)
		return (NULL);
	else
	{
		return ((char *)ft_memset(str, 0, size));
	}
}
