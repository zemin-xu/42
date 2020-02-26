/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_format.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:10:23 by zexu              #+#    #+#             */
/*   Updated: 2020/01/19 18:08:49 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FORMAT_H
# define PF_FORMAT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../utils/pf_utils.h"
# include "../flag/pf_flag.h"

# define FORMAT_SET "cspdiuxX%"

typedef struct		s_pf
{
	char			type_format;
	char			*str_before_flag;
	size_t			len_before_flag;
	int				is_left_aligned;
	int				leading_zero;
	int				precision_width;
	int				minimum_width;
	char			*str_after_flag;
	size_t			len_after_flag;
	struct s_output	*next;
}					t_pf;
int					pf_signed_int(va_list argp, t_output **res);
int					pf_unsigned_int(va_list argp, t_output **res);
int					pf_hex(va_list argp, t_output **res, int is_maj);
int					pf_pointer(va_list argp, t_output **res);
int					pf_char(va_list argp, t_output **res);
int					pf_str(va_list argp, t_output **res);
int					pf_percentage(t_output **res);
int					pf_pad(t_output *str, size_t pad_len,
							size_t prec_len, char c);
int					pf_precise(t_output *str, size_t prec_len);

t_pf				*pf_new(void *content, char type);
t_pf				*pf_last(t_pf **head);
int					pf_add(t_pf **head, t_pf *new);
int					pf_free(t_pf **head);
int					pf_flag(t_pf *curr);
int					pf_print(t_pf *head);
#endif
