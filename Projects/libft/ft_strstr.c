#include "libft.h"

static int			compare(const char *big, const char *little)
{
	while (*big && *little)
	{
		if (*big != *little)
			return (0);
		big++;
		little++;
	}
	return (*little == '\0');
}


char				*ft_strstr(const char *big, const char *little)
{
	while (*big)
	{
		if ((*big == *little) && compare(big, little))
			return ((char *)big);
		big++;
	}
	return (NULL);
}
