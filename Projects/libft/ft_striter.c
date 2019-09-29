/*
** apply the function 'f' to each character of the string passed as argu
**
** each character is passed by address to 'f' to be modified if necessary
*/

#include "libft.h"

void				ft_striter(char *s, void (*f)(char *))
{
	if (s == NULL || f == NULL)
		return ;
	while (*s)
	{
		(*f)(s);
		s++;
	}
}
