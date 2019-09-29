#include "libft.h"

int			ft_atoi(const char *string)
{
	int		res;
	int		sign;
	int		i;

	res = 0;
	sign = 1;
	i = 0;
	while (string[i] && (string[i] == ' ' || string[i] == '\n' || 		
			string[i] == '\t' || string[i] == '\v' || string[i] == '\f'
			|| string[i] == '\r'))
		i++;
	if (string[i] == '-')
		sign *= -1;
	if (string[i] == '-' || string[i] == '+')
		i++;
	while (string[i] >= '0' && string[i] <= '9')
	{
		res = res * 10 + (string[i] - '0');
		i++;
	}
	return (res * sign);
}
