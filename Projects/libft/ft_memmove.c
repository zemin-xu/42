#include "libft.h"

void				*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;
	unsigned char	*c_dst;
	unsigned char	*c_src;

	c_dst = (unsigned char *)dst;
	c_src = (unsigned char *)src;
	if(c_dst < c_src)
		return (ft_memcpy(dst, src, len));
	else
	{
		i = len;
		while (i > 0)
		{
			*(c_dst + i - 1) = *(c_src + i - 1);
			i--;
		}
		return (dst);
	}
}
