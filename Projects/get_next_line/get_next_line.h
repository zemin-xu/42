/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/01 16:59:12 by zexu              #+#    #+#             */
/*   Updated: 2019/11/03 16:25:50 by zexu             ###   ########.fr       */
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

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <unistd.h>
#include <stdlib.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE	512
#endif

typedef struct			s_gnl_list
{
	int					fd;
	int					incomplete;
	char				*content;
	struct s_gnl_list	*next;
}						t_gnl_list;

t_gnl_list				*gnl_new(char *content, int fd, int incomplete);
void					gnl_push_back(t_gnl_list **head, t_gnl_list *new);
int						gnl_search(t_gnl_list *head, int fd);
char					*gnl_fetch(t_gnl_list **head, int fd);
void					gnl_free_one(t_gnl_list **head, t_gnl_list *target);

char					*strdup_with_ends(char *s, size_t start, size_t end);
int						get_next_line(int fd, char **line);
#endif
