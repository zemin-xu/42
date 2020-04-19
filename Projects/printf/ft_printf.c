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

/*
** 'va_start' takes two arguments, a 'va_list' object and a reference to the
** function's last parameter (the one before the ellipsis; the macro uses this
** to get its bearings). It initialises the 'va_list' object for use by
** 'va_arg' or 'va_copy'.
**
** 'va_arg' takes two arguments, a 'va_list' object previous initialised and
** a type descriptor. It expands to the next variable argument, and has the
** specified type. Successive invocations of 'va_arg' allow processing each of
** the variable arguments in turn.
**
** 'va_end' takes one argument, a 'va_list' object. It serves to clean up.
**
** 'va_copy' takes two arguments, both of them 'va_list' objects. It clones
** the second (must be initialised) into the first.
*/

/*
**	----------------------------Format Characters----------------------------
** 'diouxX': The int (or appropriate variant) argument is converted to signed
** decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned
** hexadecimal (x and X) notation.  The letters ``abcdef'' are used for x
** conversions; the letters ``ABCDEF'' are used for X conversions.
** The precision, if any, gives the minimum number of digits that must appear;
** if the converted value requires fewer digits, it is padded on the left
** with zeros.
**
** 'c': The first byte of argument is printed.
**
** 's': Bytes from the string argument are printed until the end is reached
** or until the number of bytes indicated by the precision specification is
** reached; however if the precision is 0 or missing, the string is printed
** entirely.
**
** 'p': The void * pointer argument is printed in hexadecimal.
**
**	------------------------------Flags--------------------------------------
** '0': Zero padding. The converted value is padded on the left with zeros
** rather than blanks. If a precision is given with a numeric conversion, the 0
** flag is ignored.
**
** '-': A negative field width flag; the converted value is to be left adjusted
** on the field boundary. The converted value is padded on the right side with
** blanks, rather than on the left with blanks or zeros. A '-' overrides a '0'
** if both are given.
**
** ''': Decimal conversions(d, u or i) or the integral portion of a floating
** point conversion(f or F) should be grouped and separated by thousands using
** non-monetary separator returned by localeconv.
**
**	------------------------------Field Width-------------------------------
** An optional digit string specifying a field width; if the output string
** has fewer bytes than the field width it will be blank-padded on the left
** to make up the field width(a leading zero is a flag, but an embedded zero
** is part of a field width).
**
**	------------------------------Precision---------------------------------
** An optional period, '.', followed by an optional digit string giving a
** precision which specifies the number of digits to appear after the decimal
** point, for 'e' and 'f' formats, or the maximum number of bytes to be printed
** from a string; if the digit string is missing, the precision is treated as
** zero.
**
** https://www.lix.polytechnique.fr/~liberti/public/computing/prog/c/C/FUNC
** TIONS/format.html
*/

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

static int parse_format(va_list argp, char const **fmt_str_p,
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

static int format_str(va_list argp, char const **fmt_str_p, t_pf **head_ref)
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
		ft_putstr_fd("Not implemented yet", 1);
		return (-1);
	}
}

static int normal_str(char const **fmt_str_p, t_pf **head_ref)
{
	int i;
	char *str;
	t_pf *new;

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

int ft_printf(char const *format, ...)
{
	va_list argp;
	t_pf *head;
	int ret_value;

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
	ret_value = t_pf_output(head);
	if (t_pf_free(&head) == -1)
		return (-1);
	return (ret_value);
}
