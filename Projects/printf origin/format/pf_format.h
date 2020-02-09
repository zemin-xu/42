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

typedef struct		s_output
{
	char			format_type;
	char			*content;
	size_t			length;
	struct s_flag	*flag;
	struct s_output	*next;
}					t_output;
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
t_output			*pf_output_new(void *content, char type);
t_output			*pf_output_last(t_output **head);
int					pf_output_add(t_output **head, t_output *new);
int					pf_output_free(t_output **head);
int					pf_output_flag(t_output *curr);
int					pf_output_pad(t_output *curr);
int					pf_output_print(t_output *head);
#endif
