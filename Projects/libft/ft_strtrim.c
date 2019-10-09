/*
** allocate and return a copy of the string given as argument without the
** characters specified in the 'set' argument at the beginning and the end of
** the string
**
** return NULL if the allocation fails
*/

#include "libft.h"
/*
char				*ft_strtrim(char const *s, char const *set)
{
	char			*str;
	size_t			count;
	size_t			i;
//  to delete
	ft_strlen(set);
	if (s == NULL)
		return (NULL);
	i = 0;
	while (*(s + i) == ' ' || *(s + i) == '\n' || *(s + i) == '\t')
		i++;
	count = i;
	i = 0;
	if (*(s + count + i))
	{
		while (*(s + ft_strlen(s) - 1 - i) == ' ' || *(s + ft_strlen(s) - 1 - i)
				== '\n' || *(s + ft_strlen(s) - 1 - i) == '\t')
			i++;
	}
	if ((str = (char *)malloc(ft_strlen(s) - count - i + 1)) == NULL)
		return (NULL);
	ft_strncpy(str, s + count, ft_strlen(s) - count - i);
	*(str + ft_strlen(s) - count - i) = '\0';
	return (str);
}
*/
