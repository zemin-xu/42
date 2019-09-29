#include "libft.h"

char				*ft_strncpy(char *to, const char *from, size_t size)
{
    unsigned int	i;

    i = 0;
    while (from[i] && i < size)
    {
        to[i] = from[i];
        i++;
    }
    while (i < size)
    {
        to[i] = '\0';
        i++;
    }
    return (to);
}
