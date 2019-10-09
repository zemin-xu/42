#include "libft.h"

char		*ft_strcpy(char *to, const char *from)
{
    int		i;

    i = 0;
    while (from[i])
    {
        to[i] = from[i];
        i++;
    }
    to[i] = from[i];
    return (to);
}
