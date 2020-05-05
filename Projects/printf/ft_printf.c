/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:42:38 by zexu              #+#    #+#             */
/*   Updated: 2020/01/12 20:16:10 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		parse_flag(va_list argp, char const *format, t_pf *new)
{
	int			wildcard;

	new->has_flag = 1;
	if (*format == '0' && new->pad_num == -1 && new->precise_num == -1)
		new->is_padded_with_zero = 1;
	else if (*format == '-')
		new->is_left_justified = 1;
	else if (*format == '.')
		new->precise_num = 0;
	else if (*format == '*')
	{
		if ((wildcard = va_arg(argp, int)) < 0)
			return (-1);
		pf_flag_read_int(new, wildcard);
	}
	else
		pf_flag_read_char(new, *format);
	return (0);
}

static int		parse_format(va_list argp, char const **fmt_str_p,
						t_pf **res, t_pf *new)
{
	int ret;

	ret = -1;
	if (!fmt_str_p || !res)
		return (-1);
	if (**fmt_str_p == 'c')
		ret = pf_char(argp, res, new);
	else if (**fmt_str_p == 's')
		ret = pf_str(argp, res, new);
	else if (**fmt_str_p == 'p')
		ret = pf_pointer(argp, res, new);
	else if (**fmt_str_p == 'd' || **fmt_str_p == 'i')
		ret = pf_signed_int(argp, res, new);
	else if (**fmt_str_p == 'u')
		ret = pf_unsigned_int(argp, res, new);
	else if (**fmt_str_p == 'x')
		ret = pf_hex(argp, res, new, 0);
	else if (**fmt_str_p == 'X')
		ret = pf_hex(argp, res, new, 1);
	else if (**fmt_str_p == '%')
		ret = pf_percentage(res, new);
	(*fmt_str_p)++;
	return (ret);
}

static int		format_str(va_list argp,
				char const **fmt_str_p, t_pf **head_ref)
{
	t_pf	*new;

	if (!fmt_str_p || !head_ref)
		return (-1);
	(*fmt_str_p)++;
	if (!(new = t_pf_init(0, '?')))
		return (-1);
	while (ft_strchr(FLAG_SET, **fmt_str_p))
	{
		parse_flag(argp, *fmt_str_p, new);
		(*fmt_str_p)++;
	}
	if (ft_strchr(FORMAT_SET, **fmt_str_p))
		return (parse_format(argp, fmt_str_p, head_ref, new));
	else
	{
		free(new);
		ft_putstr_fd("Not implemented yet", 1);
		t_pf_free(head_ref);
		return (-1);
	}
}

static int		normal_str(char const **fmt_str_p, t_pf **head_ref)
{
	int			i;
	char		*str;
	t_pf		*new;

	i = 0;
	while (*(*fmt_str_p + i) && *(*fmt_str_p + i) != '%')
		i++;
	if (!(str = ft_strsub(*fmt_str_p, 0, i)))
		return (-1);
	if (!(new = t_pf_init(str, 's')))
		return (-1);
	if (t_pf_add(head_ref, new) == -1)
		return (-1);
	*fmt_str_p += i;
	return (0);
}

int				ft_printf(char const *format, ...)
{
	va_list		argp;
	t_pf		*head;
	int			ret_value;

	if (*format == '\0')
		return (0);
	head = NULL;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%' && format_str(argp, &format, &head) == -1)
			return (-1);
		else if (normal_str(&format, &head) == -1)
			return (-1);
	}
	va_end(argp);
	t_pf_flag_parse(head);
	ret_value = t_pf_output(head);
	if (t_pf_free(&head) == -1)
		return (-1);
	return (ret_value);
}
