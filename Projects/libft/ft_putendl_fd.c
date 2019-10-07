/*
** output the string 's' to the file descriptor 'fd' followed by a '\n' 
*/

#include "libft.h"

void				ft_putendl_fd(char *s, int fd)
{
	while (*s)
	{
		ft_putchar_fd(*s, fd);
		s++;
	}
	ft_putchar_fd('\n', fd);
}
