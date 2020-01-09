#include "pf_format.h"

int			pf_signed_int(va_list argp, t_output **res)
{
	char	*str;
	t_output *new;

	if (!(str = ft_itoa(va_arg(argp, int))))
		return (-1);
	if (!(new = t_output_new(str, 'i')))
		return (-1);
	return (t_output_add(res, new));
}

int			pf_unsigned_int(va_list argp, t_output **res)
{
	char	*str;
	t_output *new;

	if (!(str = ft_uitoa(va_arg(argp, unsigned int))))
		return (-1);
	if (!(new = t_output_new(str, 'u')))
		return (-1);
	return (t_output_add(res, new));
}

int			pf_hex(va_list argp, t_output **res, int is_maj)
{
	char	*str;
	t_output *new;

	if (!(str = ft_hextoa(va_arg(argp, unsigned int), is_maj)))
		return (-1);
	if (!(new = t_output_new(str, 'x')))
		return (-1);
	return (t_output_add(res, new));
}

int			pf_pointer(va_list argp, t_output **res)
{
	char	*str;
	t_output *new;

	if (!(str = ft_ptoa(va_arg(argp, void *))))
		return (-1);
	if (!(new = t_output_new(str, 'p')))
		return (-1);
	return (t_output_add(res, new));
}

