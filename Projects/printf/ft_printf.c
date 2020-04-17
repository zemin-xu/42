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
#include <stdio.h>

static int		parse_flag(va_list argp, char const *format, t_flag *flag)
{
	int			wildcard;

	flag->has_flag = 1;
	if (*format == '0' && !flag->is_padded && !flag->is_precised)
		flag->is_padded = 2;
	else if (*format == '-')
		flag->is_left_justified = 1;
	else if (*format == '.')
		flag->is_precised = 1;
	else if (*format == '*')
	{
		if ((wildcard = va_arg(argp, int)) < 0)
			return (-1);
		pf_flag_read_int(flag, wildcard);
	}
	else
		pf_flag_read_char(flag, *format);
	return (0);
}

static int		parse_format(va_list argp, char const **format,
				t_pf **res, t_flag *flag)
{
	int			ret;

	ret = -1;
	if (!format || !res || !flag)
		return (-1);
	if (**format == 'c')
		ret = pf_char(argp, res);
	else if (**format == 's')
		ret = pf_str(argp, res);
	else if (**format == 'p')
		ret = pf_pointer(argp, res);
	else if (**format == 'd' || **format == 'i')
		ret = pf_signed_int(argp, res);
	else if (**format == 'u')
		ret = pf_unsigned_int(argp, res);
	else if (**format == 'x')
		ret = pf_hex(argp, res, 0);
	else if (**format == 'X')
		ret = pf_hex(argp, res, 1);
	else if (**format == '%')
		ret = pf_percentage(res);
	t_flag_free(pf_output_last(res)->flag);
	pf_output_last(res)->flag = flag;
	(*format)++;
	return (ret);
}

static int		format_str(va_list argp, char const **format, t_pf **res)
{
	t_flag		*flag;

	if (!format || !res || !(flag = t_flag_init()))
		return (-1);
	(*format)++;
	while (ft_strchr(FLAG_SET, **format))
	{
		if (parse_flag(argp, *format, flag) == -1)
			return (-1);
		(*format)++;
	}
	if (ft_strchr(FORMAT_SET, **format))
		return (parse_format(argp, format, res, flag));
	else
	{
		ft_putstr_fd("Not implemented yet", 1);
		return (-1);
	}
}

static int		normal_str(char const **format, t_pf **res)
{
	int			i;
	char		*str;
	t_pf	*new;

	i = 0;
	while (*(*format + i) && *(*format + i) != '%')
		i++;
	if (!(str = ft_strsub(*format, 0, i)))
		return (-1);
	if (!(new = pf_output_new(str, 's')))
		return (-1);
	if (pf_output_add(res, new) == -1)
		return (-1);
	*format += i;
	return (0);
}

int				ft_printf(char const *format, ...)
{
	va_list		argp;
	t_pf	*res;
	int			ret;

	res = NULL;
	va_start(argp, format);
	while (*format)
	{
		if (*format == '%' && format_str(argp, &format, &res) == -1)
			return (-1);
		else if (normal_str(&format, &res) == -1)
			return (-1);
	}
	va_end(argp);
	ret = pf_output_print(res);
	if (pf_output_free(&res) == -1)
		return (-1);
	return (ret);
}
