/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 20:15:37 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:15:38 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PF_FLAG_H
# define PF_FLAG_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>

# include "../utils/pf_utils.h"

# define FLAG_SET "-.*0123456789"

typedef struct				s_flag
{
	int has_flag;

	int is_left_justified;
	int is_padded;
	int pad_num;
	int is_precised;
	int precise_num;
}							t_flag;
t_flag						*t_flag_init(void);
void						t_flag_free(t_flag *flag);

void						pf_flag_read_char(t_flag *flag, char num);
void						pf_flag_read_int(t_flag *flag, int num);

#endif
