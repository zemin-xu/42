#ifndef LIBFT_H
# define LIBFT_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

typedef	struct		s_list
{
	struct s_list	*next;
	void			*data;
}					t_list;

t_list		*ft_create_elem(void *data);
int			ft_list_size(t_list *begin_list);
void		ft_list_push_back(t_list **begin_list, void *data);
void		ft_list_push_front(t_list **begin_list, void *data);
t_list		*ft_list_last(t_list *begin_list);
t_list		*ft_list_push_params(int ac, char **av);
void		ft_list_clear(t_list **begin_list);
t_list		*ft_list_at(t_list *begin_list, unsigned int nbr);
void		ft_list_reverse(t_list **begin_list);
void		ft_list_foreach(t_list *begin_list, void (*f)(void *));
void		ft_list_remove_front(t_list **begin_list);
void		ft_list_swap(t_list **begin_list);
void		ft_list_rotate(t_list **begin_list);
void		ft_list_rotate_reverse(t_list **begin_list);

void		*ft_memset(void *block, int c, size_t size);
void		ft_bzero(void *block, size_t size);
void		*ft_memcpy(void *to, const void *from, size_t size);
void		*ft_memccpy(void *to, const void *from, int c, size_t size);
void		*ft_memmove(void *to, const void *from, size_t size);
void		*ft_memchr(const void *block, int c, size_t size);
int			ft_memcmp(const void *a1, const void *a2, size_t size);

size_t		ft_strlen(const char *s);
char		*ft_strdup(const char *s);
char		*ft_strcpy(char *to, const char *from);
char		*ft_strncpy(char *to, const char *from, size_t size);
char		*ft_strcat(char *to, const char *from);
char		*ft_strncat(char *to, const char *from, size_t size);
size_t		ft_strlcat(char *to, const char *from, size_t size);
char		*ft_strchr(const char *string, int c);
char		*ft_strrchr(const char *string, int c);
char		*ft_strstr(const char *haystack, const char *needle);
char		*ft_strnstr(const char *haystack, const char *needle,
						size_t size);
int			ft_strcmp(const char *s1, const char *s2);
int			ft_strncmp(const char *s1, const char *s2, size_t size);
int			ft_atoi(const char *string);
int			ft_isalpha(int c);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

void		*ft_memalloc(size_t size);
void		ft_memdel(void **ap);
char		*ft_strnew(size_t size);
void		ft_strdel(char **as);
void		ft_strclr(char *s);
void		ft_striter(char *s, void (*f)(char *));
void		ft_striteri(char *s, void (*f)(unsigned int, char *));
char		*ft_strmap(char const *s, char (*f)(char));
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int			ft_strequ(char const *s1, char const *s2);
int			ft_strnequ(char const *s1, char const *s2, size_t n);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strtrim(char const *s);
char		**ft_strsplit(char const *s, char c);
char		*ft_itoa(int n);
void		ft_putchar(char c);
void		ft_putstr(char const *s);
void		ft_putendl(char const *s);
void		ft_putnbr(int n);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char const *s, int fd);
void		ft_putendl_fd(char const *s, int fd);
void		ft_putnbr_fd(int n, int fd);

#endif
