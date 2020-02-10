/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utils.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:15:11 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:25:30 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_UTILS_H
# define PF_UTILS_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(char const *s);
char	*ft_strsub(char const *s, unsigned int start, size_t len);
char	*ft_strchr(char const *string, int c);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
char	*ft_uitoa(unsigned int n);
char	*ft_hextoa(unsigned int n, int is_maj);
char	*ft_ptoa(void *n);
void	*ft_memmove(void *to, const void *from, size_t size);
void	*ft_memcpy(void *to, const void *from, size_t size);

#endif
