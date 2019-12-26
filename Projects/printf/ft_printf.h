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

#include "libft/libft.h"
#include <unistd.h>
#include <stdlib.h>
#include <stdarg.h>

int				ft_printf(const char *format, ...);
typedef struct      s_output
{
    char            *content;
    size_t          length;
    struct s_output *next;
}                   t_output;

size_t		ft_strlen(const char *s);
size_t		ft_strlen(const char *s);

t_output        *t_output_new(void *content);
t_output        *t_output_last(t_output **head);
void    	    t_output_add(t_output **head, t_output *new);
void            t_output_free(t_output **head);
void            t_output_read(t_output *head);

#endif


