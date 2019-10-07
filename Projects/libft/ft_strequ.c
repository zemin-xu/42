/*
** lexicographical comparison between 's1' and 's2'
**
** return 0 if the two string are identical, return 1 if not
*/

#include "libft.h"

int					ft_strequ(char const *s1, char const *s2)
{
	if (s1 == NULL || s2 == NULL)
		return (0);
	else
	{
		while (*s1)
		{
			if (*s1 != *s2)
				return (0);
			else
			{
				s1++;
				s2++;
			}
		}
		if (*s2 == *s1)
			return (1);
		else
			return (0);
	}
}
