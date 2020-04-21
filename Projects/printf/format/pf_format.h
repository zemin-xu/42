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

# define FLAG_SET "-.*0123456789"
# define FORMAT_SET "cspdiuxX%"

typedef struct		s_pf
{
	char			format_type;
	char			*str_before;
	int				is_num_with_minus;
	int				has_flag;
	int				is_left_justified;
	int				is_padded_with_zero;
	int				pad_num;
	int				precise_num;
	char			*str_after;
	size_t			len;
	struct s_pf		*next;
}					t_pf;
int					pf_signed_int(va_list argp, t_pf **head_ref, t_pf *new);
int					pf_unsigned_int(va_list argp, t_pf **head_ref, t_pf *new);
int					pf_hex(va_list argp, t_pf **head_ref, t_pf *new, int is_maj);
int					pf_pointer(va_list argp, t_pf **head_ref, t_pf *new);
int					pf_char(va_list argp, t_pf **head_ref, t_pf *new);
int					pf_str(va_list argp, t_pf **head_ref, t_pf *new);
int					pf_percentage(t_pf **head_ref, t_pf *new);
int					pf_pad(t_pf *str, size_t pad_len,
							size_t prec_len, char c);
int					pf_precise(t_pf *str, size_t prec_len);
t_pf				*t_pf_init(void *content, char type);
t_pf				*t_pf_last(t_pf *head);
int					t_pf_add(t_pf **head_ref, t_pf *new);
int					t_pf_free(t_pf **head_ref);

void				t_pf_flag_parse(t_pf *head);
int					t_pf_output(t_pf *head);

void				pf_flag_read_char(t_pf *new, char num);
void				pf_flag_read_int(t_pf *new, int num);
char	*pf_join_with_pad_zero(char const *s, size_t str_len, size_t pad_len, int is_left);
char	*pf_join_with_pad_space(char const *s, size_t str_len, size_t pad_len, int is_left);
char	*pf_join_prec_with_num(char const *s, size_t num_len, size_t prec_len, int is_minus);


void				pf_flag_parse_s(t_pf *list);
void				pf_flag_parse_c(t_pf *list);
void				pf_flag_parse_i(t_pf *list);
#endif
