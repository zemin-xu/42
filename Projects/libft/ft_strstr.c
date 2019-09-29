/*
** search 'haystack' for a substring 'needle'
**
** return a pointer into the string 'haystack' that is the first byte
** of the substring, or a null pointer if no match
** if 'needle' is an empty string, the function returns 'haystack'
*/ 

#include "libft.h"

static int			compare(const char *haystack, const char *needle)
{
	while (*haystack && *needle)
	{
		if (*haystack != *needle)
			return (0);
		haystack++;
		needle++;
	}
	return (*needle == '\0');
}


char				*ft_strstr(const char *haystack, const char *needle)
{
	while (*haystack)
	{
		if ((*haystack == *needle) && compare(haystack, needle))
			return ((char *)haystack);
		haystack++;
	}
	return (NULL);
}
