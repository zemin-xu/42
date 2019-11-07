/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:42:38 by zexu              #+#    #+#             */
/*   Updated: 2019/11/07 22:50:22 by zexu             ###   ########.fr       */
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
 **	-------------------------Conversion Specifiers---------------------------
 ** %diouxX: The int (or appropriate variant) argument is converted to signed
 ** decimal (d and i), unsigned octal (o), unsigned decimal (u), or unsigned 
 ** hexadecimal (x and X) notation.  The letters ``abcdef'' are used for x 
 ** conversions; the letters ``ABCDEF'' are used for X conversions.  
 ** The precision, if any, gives the minimum number of digits that must appear;
 ** if the converted value requires fewer digits, it is padded on the left 
 ** with zeros.
 */

#include "ft_printf.h"
#include <stdio.h>

int					ft_printf(const char *format, ...)
{
	va_list			argp;
	
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
			{
				unsigned int x = (unsigned int)va_arg(argp, int);
				ft_putnbr_fd(x, 1);
			}
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
			ft_putchar_fd(*format, 1);	
		format++;
	}
	va_end(argp);
	return (0);
}

int					main()
{
	int a = -5;
	int b = 0x0b;
	int *p = &a;
	//ft_printf("%d%%%s%p%p$$", 100, "!!sfggd!!");
	ft_printf("%u\n", a);
	printf("%u\n", a);
	return 0;
}

