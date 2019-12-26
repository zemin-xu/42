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

int					ft_printf(const char *format, ...)
{
	va_list			argp;
	t_output		*res;
	int				ret;

	res = NULL;
	ret = 0;

	t_output *ta = t_output_new("where are you");
	t_output *tb = t_output_new("Fine thank you!");
	t_output *tc = t_output_new("and you!!!");
	t_output_add(&res, ta); 
	t_output_add(&res, tb); 
	t_output_add(&res, tc); 
	t_output_read(res);
	t_output_free(&res);

	va_start(argp, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
				 ft_putchar_fd((char)va_arg(argp, int), 1);
			else if (*format == 's')
				ft_putstr_fd(va_arg(argp, char*), 1);
			else if (*format == 'p')
				ft_putchar_fd('p', 1);
			else if (*format == 'd' || *format == 'i')
				ft_putnbr_fd(va_arg(argp, int), 1);
			else if (*format == 'u')
				ft_putnbr_fd((unsigned int)(va_arg(argp, int)), 1);
			else if (*format == 'x')
				ft_putchar_fd('x', 1);
			else if (*format == 'X')
				ft_putchar_fd('X', 1);
			else if (*format == '%')
				ft_putchar_fd('%', 1);
			else
				ft_putstr_fd("Not implemented yet", 1);
		}
		else
		{
			ret++;
			ft_putchar_fd(*format, 1);	
		}
		format++;
	}
	
	va_end(argp);
	
	return (0);
}

int					main()
{
	ft_printf("@@@");
	while(1)
	{

	}
	return 0;
}

