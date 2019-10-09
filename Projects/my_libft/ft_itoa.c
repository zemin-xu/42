/*
** allocate and return a new created string ending with '\0' representing
** the integer 'n' given as argument.
*/

#include "libft.h"

static int			length(int n)
{
	long			tmp;
	int				count;

	tmp = (long)n;
	count = 1;
	if (tmp < 0)
	{
		count++;
		tmp *= -1;
	}
	while (tmp >= 10)
	{
		tmp /= 10;
		count++;
	}
	return (count);
}

char				*ft_itoa(int n)
{
	int				len;
	int				i;
	char			*str;
	long			tmp;

	len = length(n);
	tmp = (long)n;
	if ((str = (char *)malloc((len + 1) * sizeof(char))) == NULL)
		return (NULL);
	*(str + len) = '\0';
	i = 0;
	if (tmp < 0)
	{
		*str = '-';
		tmp *= -1;
		i = 1;
	}
	while (len > i)
	{
		*(str + --len) = '0' + tmp % 10;
		tmp /= 10;
	}
	return (str);
}
