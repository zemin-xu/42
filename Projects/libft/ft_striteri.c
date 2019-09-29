/*
** apply the function 'f' to each character of the string passed as
** argument and pass its index as first argument
**
*/

#include "libft.h"

void				ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	unsigned int	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (*s)
	{
		(*f)(i, s);
		s++;
		i++;
	}
}
