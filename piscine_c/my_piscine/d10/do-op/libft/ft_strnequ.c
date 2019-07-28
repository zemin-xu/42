#include "libft.h"

int					ft_strnequ(char const *s1, char const *s2, size_t n)
{
	size_t			i;	

	if (n == 0)
		return (1);
	else if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		i = 0;
		while (*(s1 + i) && i < n - 1)
		{
			if (*(s1 + i) != *(s2 + i))
				return (0);
			else
				i++;
		}
		if (*s2 == *s1)
			return (1);
		else
			return (0);
	}
}
