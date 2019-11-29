/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/29 22:29:38 by zexu              #+#    #+#             */
/*   Updated: 2019/11/29 22:29:55 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Using -D in gcc command is to define compile time macros in code.
*/

/*
** Static variable remains in memory while the program is running, unlike a
** normal or auto variable which will be destroyed hwen a function call ends.
**
** Static variables are allocated momory in data segment, not stack segment.
**
** Static variables are initialized as 0 if not initialized explicitly.
**
** In C, static variables can only be initialized using constant literals.
** The reason is all objects with static storage duration must be initialized
** before execution of main() starts.
**
** Static variables should not be declared inside structure.
*/

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	512
# endif

typedef struct			s_gnl_list
{
	int					fd;
	int					incomplete;
	char				*content;
	struct s_gnl_list	*next;
}						t_gnl_list;

t_gnl_list				*gnl_new(t_gnl_list **head, char *content, int fd,
								int incomplete);
void					gnl_push_back(t_gnl_list **head, t_gnl_list *new);
int						gnl_search(t_gnl_list *head, int fd);
char					*gnl_fetch(t_gnl_list **head, int fd);
void					gnl_free_one(t_gnl_list **head, t_gnl_list *target);

char					*gnl_strdup(char *s, size_t start, size_t end);
char					*ft_strncpy(char *to, const char *from, size_t size);
char					*ft_strjoin(char const *s1, char const *s2);
void					get_next_line_2(t_gnl_list **tmp, int fd, char *buffer,
										int read_value);
int						get_next_line(int fd, char **line);
#endif
