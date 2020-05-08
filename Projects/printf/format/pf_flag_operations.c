/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_flag_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zexu <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/05 16:50:38 by zexu              #+#    #+#             */
/*   Updated: 2020/05/05 16:50:50 by zexu             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pf_format.h"

char				*pf_join_with_pad_zero(char const *s, size_t str_len,
											size_t pad_len, int is_left)
{
	char			*str;
	size_t			i;

	if (s == NULL || (str = (char *)malloc(str_len + pad_len + 1)) == NULL)
		return (NULL);
	i = -1;
	if (is_left)
	{
		ft_strncpy(str, s, str_len);
		while (++i < pad_len)
			*(str + str_len + i) = '0';
	}
	else
	{
		while (++i < pad_len)
			*(str + i) = '0';
		ft_strncpy(str + i, s, str_len);
	}
	*(str + str_len + i) = '\0';
	return (str);
}

char				*pf_join_with_pad_space(char const *s, size_t str_len,
											size_t pad_len, int is_left)
{
	char			*str;
	int				i;

	if (s == NULL || (str = (char *)malloc(str_len + pad_len + 1)) == NULL)
		return (NULL);
	i = -1;
	if (is_left)
	{
		ft_strncpy(str, s, str_len);
		while (++i < (int)pad_len)
			*(str + str_len + i) = ' ';
	}
	else
	{
		while (++i < (int)pad_len)
			*(str + i) = ' ';
		ft_strncpy(str + i, s, str_len);
	}
	*(str + str_len + i) = '\0';
	return (str);
}

char				*pf_join_pad_c_null(size_t pad_len, int is_left)
{
	char			*str;
	int				i;

	if ((str = (char *)malloc(1 + pad_len)) == NULL)
		return (NULL);
	i = -1;
	if (is_left)
	{
		*str = '\0';
		while (++i < (int)pad_len)
			*(str + 1 + i) = ' ';
	}
	else
	{
		while (++i < (int)pad_len)
			*(str + i) = ' ';
		*(str + i) = '\0';
	}
	return (str);
}

char				*pf_join_prec_with_num(char const *s, size_t num_len,
											size_t prec_len, int is_minus)
{
	char			*str;
	int				i;

	prec_len = prec_len < 0 ? 0 : prec_len;
	if (s == NULL || (str = (char *)malloc(num_len + prec_len +
										(is_minus ? 1 : 0) + 1)) == NULL)
		return (NULL);
	i = 0;
	if (is_minus)
	{
		*(str) = '-';
		i++;
	}
	while (i < (int)prec_len + (is_minus ? 1 : 0))
	{
		*(str + i) = '0';
		i++;
	}
	ft_strncpy(str + i, s, num_len);
	*(str + num_len + i) = '\0';
	return (str);
}

char				*pf_join_prec_with_0x(char const *s, size_t num_len,
											size_t prec_len)
{
	char			*str;
	int				i;

	prec_len = prec_len < 0 ? 0 : prec_len;
	if (s == NULL || (str = (char *)malloc(num_len + prec_len + 3)) == NULL)
		return (NULL);
	i = 2;
	*str = '0';
	*(str + 1) = 'x';
	while (i < (int)prec_len + 2)
	{
		*(str + i) = '0';
		i++;
	}
	ft_strncpy(str + i, s, num_len);
	*(str + num_len + i) = '\0';
	return (str);
}
