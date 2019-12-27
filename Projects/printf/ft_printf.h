/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/07 19:18:16 by zexu              #+#    #+#             */
/*   Updated: 2019/11/07 19:18:17 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

#define FLAG_SET "-.*0123456789"
#define FORMAT_SET "cspdiuxX%"

int				ft_printf(char const *format, ...);
typedef struct      s_output
{
    char            *content;
    size_t          length;
    struct s_output *next;
}                   t_output;

size_t		ft_strlen(char const *s);
void		ft_putchar_fd(char c, int fd);
void		ft_putstr_fd(char *s, int fd);
void		ft_putnbr_fd(int n, int fd);
char		*ft_strsub(char const *s, unsigned int start, size_t len);
char		*ft_strchr(char const *string, int c);
char		*ft_itoa(int n);
char		*ft_uitoa(unsigned int n);
char		*ft_hextoa(unsigned int n, int is_maj);
char		*ft_ptoa(void *n);
char		*ft_strdup(const char *s);

t_output        *t_output_new(void *content);
t_output        *t_output_last(t_output **head);
void    	    t_output_add(t_output **head, t_output *new);
void            t_output_free(t_output **head);
void            t_output_read(t_output *head);

#endif


