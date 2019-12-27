/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:42:38 by zexu              #+#    #+#             */
/*   Updated: 2019/12/23 18:02:21 by zexu             ###   ########.fr       */
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
** than blanks. If a precision is given with a numeric conversion, the 0 flag
** is ignored.
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
** is part of a field width.
**
**	------------------------------Precision---------------------------------
** An optional period, '.', followed by an optional digit string giving a
** precision which specifies the number of digits to appear after the decimal
** point, for 'e' and 'f' formats, or the maximum number of bytes to be printed
** from a string; if the digit string is missing, the precision is treated as
** zero.
*/

#include "ft_printf.h"
#include <stdio.h>
int			pf_char(va_list argp, t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = (char)va_arg(argp, int);
	*(str + 1) = '\0';
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + 1);
}

int			pf_str(va_list argp, t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = ft_strdup(va_arg(argp, char *))))
		return (-1);
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + t_output_last(res)->length);
}

int			pf_signed_int(va_list argp, t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = ft_itoa(va_arg(argp, int))))
		return (-1);
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + t_output_last(res)->length);
}

int			pf_unsigned_int(va_list argp, t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = ft_uitoa(va_arg(argp, unsigned int))))
		return (-1);
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + t_output_last(res)->length);
}

int			pf_hex(va_list argp, t_output **res, int ret, int is_maj)
{
	char	*str;
	t_output *new;

	if (!(str = ft_hextoa(va_arg(argp, unsigned int), is_maj)))
		return (-1);
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + t_output_last(res)->length);
}

int			pf_pointer(va_list argp, t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = ft_ptoa(va_arg(argp, void *))))
		return (-1);
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + t_output_last(res)->length);
}


int			pf_percentage(t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = '%';
	*(str + 1) = '\0';
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);
	return (ret + 1);
}
static void parse_flag(void)
{

}

static int parse_format(va_list argp, char const **format, t_output **res, int ret)
{	
	if (**format == 'c')
		ret = pf_char(argp, res, ret);
	else if (**format == 's')
		ret = pf_str(argp, res, ret);
	else if (**format == 'p')
		ret = pf_pointer(argp, res, ret);
	else if (**format == 'd' || **format == 'i')
		ret = pf_signed_int(argp, res, ret);
	else if (**format == 'u')
		ret = pf_unsigned_int(argp, res, ret);
	else if (**format == 'x')
		ret = pf_hex(argp, res, ret, 0);
	else if (**format == 'X')
		ret = pf_hex(argp, res, ret, 1);
	else if (**format == '%')
		ret = pf_percentage(res, ret);
	(*format)++;
	return (ret);
}

static int format_str(va_list argp, char const **format, t_output **res, int ret)
{
	(*format)++;
	if (ft_strchr(FORMAT_SET, **format))
		return (parse_format(argp, format, res, ret));
	else if (ft_strchr(FORMAT_SET, **format))
		parse_flag();
	else
	{
		ft_putstr_fd("Not implemented yet", 1);
		return (-1);
	}

	return (ret);
}

static int normal_str(char const **format, t_output **res, int ret)
{
	int start;
	char *str;
	t_output *new;

	start = ret;
	while (*(*format + ret - start) && *(*format + ret - start) != '%')
		ret++;

	/* add string into list */
	if (!(str = ft_strsub(*format, 0, ret - start)))
		return (-1);
	if (!(new = t_output_new(str)))
		return (-1);
	t_output_add(res, new);

	*format += (ret - start);
	return (ret);
}

int ft_printf(char const *format, ...)
{
	va_list argp;
	t_output *res;
	int ret;

	res = NULL;
	ret = 0;
	va_start(argp, format);
	while (*format != '\0')
	{
		if (*format == '%')
			ret = format_str(argp, &format, &res, ret);
		else
			ret = normal_str(&format, &res, ret);
	}
	va_end(argp);
	t_output_read(res);
	t_output_free(&res);
	return (ret);
}

int main()
{
	int a = 10;
	int *p = &a;
	printf("%p\n", p);
	ft_printf("\n%p", p);
	return 0;
}
