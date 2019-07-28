#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef				struct s_stack
{
	t_list			*top;
	unsigned int	size;
}					t_stack;

t_stack				*init_stack(int *array)
{
	t_stack			*p_stack;
	unsigned int	i;

	if((p_stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	p_stack->size = sizeof(array) / sizeof(int) + 1;
	ft_putnbr((int)p_stack->size);
	i = 0;
	while (i < p_stack->size)
	{
		ft_list_push_front(&(p_stack->top), (array + i));
		i++;
	}
	return (p_stack);
}


int				main()
{
	int			array[3] = {10, 20, 30};
	t_stack *stack = init_stack(array);
	printf("%d", *(int *)stack->top->data);

	return 0;
}
