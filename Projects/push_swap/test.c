#include <stdlib.h>
#include <stdio.h>

typedef			struct s_stack
{
	int			top;
	unsigned int	size;
	int			*array;
}				t_stack;

t_stack			*create_stack(unsigned int size)
{
	t_stack 	*stack;

	stack = (t_stack *)malloc(sizeof(t_stack));
	stack->size = size;
	stack->top = -1;
	stack->array = (int*)malloc(stack->size *sizeof(int));
	return stack;
}

void			push(t_stack *stack, int item)
{
	stack->array[++stack->top] = item;
	printf("%d pushed to stack\n", item);
}

int				main()
{
	t_stack *stack = create_stack(10);
	push(stack, 10);
	push(stack, 20);
	push(stack, 30);
	printf("%d %d %d", stack->array[0], stack->array[1],
			stack->array[2]);

	return 0;
}
