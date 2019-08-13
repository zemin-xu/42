#include "libft/libft.h"
#include <stdlib.h>
#include <stdio.h>

typedef				struct s_stack
{
	t_list			*top_a;
	t_list			*top_b;
	t_list			*last_a;
	t_list			*last_b;
	unsigned int	size_a;
	unsigned int	size_b;
}					t_stack;

t_stack				*init_stack(int *array, unsigned long len)
{
	t_stack			*p_stack;
	unsigned long	i;

	if((p_stack = (t_stack *)malloc(sizeof(t_stack))) == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		ft_list_push_front(&(p_stack->top_a), (void *)(array + i));
		i++;
	}
	p_stack->size_a = (unsigned int)i;
	p_stack->size_b = 0;
	return (p_stack);
}

void				sa(t_stack *stack)
{
	if (stack->size_a == 0 || stack->size_a == 1)
		return ;
	else
	{

		stack->size_b = 221;
	}


}

void				pa(t_stack *stack)
{
	if (stack->size_b > 0)
	{
		ft_list_push_front(&(stack->top_a), stack->top_b->data);	
		stack->size_a++;
		ft_list_remove_front(&(stack->top_b));
		stack->size_b--;
	}
	else
		return ;
}

void				pb(t_stack *stack)
{
	if (stack->size_a > 0)
	{
		ft_list_push_front(&(stack->top_b), stack->top_a->data);	
		stack->size_b++;
		ft_list_remove_front(&(stack->top_a));
		stack->size_a--;
	}
	else
		return ;
}

void				free_stack(t_stack *stack)
{
	if (stack == NULL)
		return ;
	else
		free(stack);
}

int				main()
{
	int			array[5] = {10, 20, 30, 40, 50};
	t_stack		*stack;

	stack = init_stack(array, sizeof(array)/sizeof(*array));
	printf("top a : %d\n", *(int *)stack->top_a->data);
	printf("size a : %u\n", stack->size_a);
	printf("size b : %u\n", stack->size_b);
	pa(stack);

	printf("top a : %d\n", *(int *)stack->top_a->data);
	printf("size a : %u\n", stack->size_a);
	printf("size b : %u\n", stack->size_b);
	free_stack(stack);
	return 0;
}
