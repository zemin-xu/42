#ifndef FT_UTILS_H
# define FT_UTILS_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
size_t		ft_strlen(char const *s);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strchr(char const *string, int c);
char		*ft_strdup(const char *s);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int n);
char		*ft_hextoa(unsigned int n, int is_maj);
char		*ft_ptoa(void *n);

#endif


