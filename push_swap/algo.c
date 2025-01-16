#include "push_swap.h"
#include "stack/stack.h"

void	ft_algo(t_stack *a, t_stack *b)
{
	while (!stack_issorted(a))
	{
		while (stack_peek(a, 0) != stack_max(a))
			ra(a);
		pa(a, b);
	}
	for (int i = 0; i < b->size; i++)
		printf("%d, ", b->a[i]);
	printf("\n");
}
