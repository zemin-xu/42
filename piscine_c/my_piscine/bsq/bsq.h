/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/26 22:57:19 by zexu              #+#    #+#             */
/*   Updated: 2019/06/26 23:26:45 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
void        trans_line(char *line, int *res, int n);
void        pass_line(int *src, int *dest, int n);
int         min(int a, int b, int c);
void        pass_value(int *a, int x, int y, int value);
void        pass_max(int *max, int *cur);
void		ft_putchar(char c);
int        ft_atoi(char *str);
void		ft_putstr(char *str);
int        count_size(int fd, char *first_line);
int        count_n(char *file_name, int *p_size);
char    **init_map(int fd, int size, int n);
char		**store_map(int n, int fd, int size);
void		print_res(int *res, char **map);

#endif
