/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush_02.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/23 17:16:30 by zexu              #+#    #+#             */
/*   Updated: 2019/06/23 21:19:49 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		num_len(char *str);
int		num_div(char *str);
int		size_num(char *str);
char	*add_zero(char *str);
char	**split_3(char *str);
void	read_outer(char **dict, int i, int flag);
int		read_inner(char **dict, char *inner, int division);
int		read_inner_2(char **dict, char *inner);
void	read_general(char **dict, char **src, int division);
char	**create_lib_2(char *buffer, int fd, char **res);
char	**create_lib(int fd);
int		test_num(char *num);

#endif
