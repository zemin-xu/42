/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <zexu@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 19:42:38 by zexu              #+#    #+#             */
/*   Updated: 2019/11/05 13:37:44 by zexu             ###   ########.fr       */
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

#include <stdarg.h>

int					ft_printf(const char *format, ...)
{
	va_list			argp;
	
	va_start(argp, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == '%')
				ft_putchar('%');
			else if (*format == 'c')
				//print char
			else if (*format == 'd')
				//print char
		}
		else
			ft_putchar(*format);	
		format++;
	}
	va_end(argp);
	return (0);
}

int					main()
{
	printf("%f\n", average(3, 1, 2, 3));
	printargs(5, 23, 2, -1, 1);
	printargs(5, -1, -1);
	return (0);
}
