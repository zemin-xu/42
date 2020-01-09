#include "pf_format.h"

int			pf_char(va_list argp, t_output **res, int ret)
{
	char	*str;
	t_output *new;

	if (!(str = (char *)malloc(sizeof(char) * 2)))
		return (-1);
	*str = (char)va_arg(argp, int);
	*(str + 1) = '\0';
	if (!(new = t_output_new(str, 'c')))
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
	if (!(new = t_output_new(str, 's')))
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
	if (!(new = t_output_new(str, '%')))
		return (-1);
	t_output_add(res, new);
	return (ret + 1);
}