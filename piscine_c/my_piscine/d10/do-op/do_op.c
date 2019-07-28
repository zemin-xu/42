void			ft_putchar(char c);
void			ft_putnbr(int n);
int				ft_atoi(char *str);
int				add(int a, int b);
int				subtract(int a, int b);
int				multiply(int a, int b);
int				divide(int a, int b);
int				modulo(int a, int b);

/*
 ** in this exercice I did not treat error case
 */

int				operation(int a, int b, int index)
{
	int (*p_operation[5])(int, int);

	p_operation[0] = add;
	p_operation[1] = subtract;
	p_operation[2] = multiply;
	p_operation[3] = divide;
	p_operation[4] = modulo;

	return (p_operation[index](a, b));
}


int				op_index(char c)
{
	if (c == '+')
		return (0);
	else if (c == '-')
		return (1);
	else if (c == '*')
		return (2);
	else if (c == '/')
		return (3);
	else if (c == '%')
		return (4);
	else
		return (-1);
}

int				main(int argc, char **argv)
{
	(void) argc;
	(void) argv;
	int			op;
	int			res;

	op = op_index(argv[2][0]);
	res = operation(ft_atoi(argv[1]), ft_atoi(argv[3]), op);
	ft_putnbr(res);
	return (0);
}
