/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabotie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/07 13:38:03 by asabotie          #+#    #+#             */
/*   Updated: 2019/10/08 14:37:29 by asabotie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTS_H
# define TESTS_H

int		g_test_id;

void	str_comp(char *str1, char *str2);
void	int_comp(int nb1, int nb2);
void	ptr_comp( void *nb1, void *nb2, int equal);
void	mem_comp( void *nb1, void *nb2, int size);

void	test_ft_memset(void);
void	test_ft_bzero(void);
void	test_ft_memcpy(void);
void	test_ft_memccpy(void);
void	test_ft_memmove(void);
void	test_ft_memchr(void);
void	test_ft_memcmp(void);
void	test_ft_strlen(void);
void	test_ft_isalpha(void);
void	test_ft_isdigit(void);
void	test_ft_isalnum(void);
void	test_ft_isascii(void);
void	test_ft_isprint(void);
void	test_ft_toupper(void);
void	test_ft_tolower(void);
void	test_ft_strchr(void);
void	test_ft_strrchr(void);
void	test_ft_strncmp(void);
void	test_ft_strlcpy(void);
void	test_ft_strlcat(void);
void	test_ft_strnstr(void);
void	test_ft_atoi(void);
void	test_ft_calloc(void);
void	test_ft_strdup(void);
void	test_ft_substr(void);
void	test_ft_strjoin(void);
void	test_ft_strtrim(void);
void	test_ft_split(void);
void	test_ft_itoa(void);
void	test_ft_strmapi(void);
void	test_ft_putchar_fd(void);
void	test_ft_putstr_fd(void);
void	test_ft_putendl_fd(void);
void	test_ft_putnbr_fd(void);
void	test_ft_lstnew(void);
void	test_ft_lstadd_front(void);
void	test_ft_lstsize(void);
void	test_ft_lstlast(void);
void	test_ft_lstadd_back(void);
void	test_ft_lstdelone(void);
void	test_ft_lstclear(void);
void	test_ft_lstiter(void);
void	test_ft_lstmap(void);

#endif
