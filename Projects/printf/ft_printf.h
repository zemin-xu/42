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

#include "utils/ft_utils.h"
#include "format/pf_format.h"

#define FLAG_SET "-.*0123456789"
#define FORMAT_SET "cspdiuxX%"

int				ft_printf(char const *format, ...);

#endif


