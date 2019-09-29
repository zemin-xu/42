/*
** return true if 'c' is a 7-bit unsigned char value that fits into
** the US/UK ASCII character set
*/

#include "libft.h"

int			ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}
