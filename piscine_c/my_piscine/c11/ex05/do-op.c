/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/27 09:33:58 by zexu              #+#    #+#             */
/*   Updated: 2019/06/27 15:20:52 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "op.h"

int		add(int a, int b)
{
	int	res;

	res = a + b;
	return (res);
}

int		minus(int a, int b)
{
	int	res;

	res = a - b;
	return (res);
}

int		multiply(int a, int b)
{
	int	res;

	res = a * b;
	return (res);
}

int		division(int a, int b)
{
	int	res;

	res = a / b;
	return (res);
}


int		modulo(int a, int b)
{
	int	res;

	res = a % b;
	return (res);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;
	i = 0;
	while (str[i])
	{
		ft_putchar(str[i]);
		i++;
	}
}

void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
		write(1, "-2147483648", 11);
	else if (nb < 0)
	{
		ft_putchar('-');
		nb *= -1;
		ft_putnbr(nb);
	}
	else if (nb >= 10)
	{
		ft_putnbr(nb / 10);
		ft_putchar(nb % 10 + '0');
	}
	else
		ft_putchar(nb % 10 + '0');
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_atoi(char *str)
{
	int	i;
	int	sign;
	int	res;

	i = 0;
	sign = 1;
	res = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' 
			|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res * sign);
}

void	parse_param(char **str, char str2, int (*f[5])(int, int))
{
	int	a;
	int	b;

	a = ft_atoi(str[1]);
	b = ft_atoi(str[3]);
	if (str2 == '+' || str2 == '-' || str2 == '/' || str2 == '%' || str2 =='*')
	{
		if (b == 0 && str2 == '/')
			ft_putstr("Stop : division by zero");
		else if (b == 0 && str2 == '%')
			ft_putstr("Stop : modulo by zero");
		else if (str2 == '+')
			ft_putnbr((*(f + 0))(a, b));
		else if (str2 == '-')
			ft_putnbr((*(f + 1))(a, b));
		else if (str2 == '*')
			ft_putnbr((*(f + 2))(a, b));
		else if (str2 == '/')
			ft_putnbr((*(f + 3))(a, b));
		else
			ft_putnbr((*(f + 4))(a, b));
	}
	else
		ft_putnbr(0);
}




int		main(int ac, char **av)
{
	int	(*op[5])(int, int);	

	if (ac != 4)
		return (0);
	else
	{
		if (ft_strlen(av[2]) != 1)
		{
			ft_putnbr(0);
			return (0);
		}
		op[0] = &add;
		op[1] = &minus;
		op[2] = &multiply;
		op[1] = &division;
		op[1] = &modulo;
		parse_param(av, av[2][0], op);
	}
	ft_putchar('\n');
	return (0);
}
