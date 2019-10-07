/*
** allocate and return an array of strings ending with '\0', obtained by 
** spliting 's' using the character 'c' as a delimiter
*/

#include "libft.h"

static int		num_strings_1(char const *s, char c, int i, int j)
{
	int			num;
	int			flag;

	num = 1;
	flag = 0;
	while (i < ft_strlen(s) - j - 1)
	{
		if(*(s + i) == c && flag == 0)
		{
			flag = 1;
			num++;
		}
		else
			flag = 0;
		i++;
	}
	return (num);
}
static int		num_strings_2(char const *s, char c)
{
	int			i;
	int			j;

	i = 0;
	j = 0;
	while (*(s + i) == c) 
		i++;
	if (ft_strlen(s) <= 0 || i == ft_strlen(s))
		return (0);
	while (*(s + ft_strlen(s) - j - 1) == c)
		j++;
	return (num_strings_1(s, c, i, j));
}

char			**ft_strsplit(char const *s, char c)
{
	ft_putnbr(num_strings_2(s, c));	
	
	return (NULL);
}
