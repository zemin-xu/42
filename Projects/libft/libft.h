/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:45:19 by zexu              #+#    #+#             */
/*   Updated: 2019/10/09 22:43:31 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <string.h>

/*
** part 1
** with problems:
** should add in part1:
** strlcpy
*/

void				*ft_memset(void *block, int c, size_t size);
void				ft_bzero(void *block, size_t size);
void				*ft_memcpy(void *to, const void *from, size_t size);
void				*ft_memccpy(void *to, const void *from, int c, size_t size);
void				*ft_memmove(void *to, const void *from, size_t size);
void				*ft_memchr(const void *block, int c, size_t size);
int					ft_memcmp(const void *a1, const void *a2, size_t size);
size_t				ft_strlen(const char *s);
size_t				ft_strlcpy(char *to, const char *from, size_t size);
size_t				ft_strlcat(char *to, const char *from, size_t size);
char				*ft_strchr(const char *string, int c);
char				*ft_strrchr(const char *string, int c);
char				*ft_strnstr(const char *haystack, const char *needle,
								size_t size);
int					ft_strncmp(const char *s1, const char *s2, size_t size);
int					ft_atoi(const char *string);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);
char				*ft_strdup(const char *s);
void				*ft_calloc(size_t count, size_t elesize);

char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				**ft_split(char const *s, char c);
char				*ft_itoa(int n);
char				*ft_strmapi(char *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);

/*
** should modify:
** strtrim strlcpy ft_lstadd_back
*/

char				**ft_strsplit(char const *s, char c);

typedef	struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

t_list				*ft_lstnew(void *content);
void				ft_lstadd_front(t_list **alst, t_list *new);
int					ft_lstsize(t_list *lst);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstadd_back(t_list **alst, t_list *new);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(void *));

#endif
