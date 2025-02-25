#include "includes/push_swap.h"
#include "stack/stack.h"

int	test(t_ps *data)
{
	t_chunk	b;

	b.pos = BOTTOM_A;
	b.size = 3;
	sort_three(data, &b);
	printf("TOP OF A: %d\n", stack_peek(data->a, 1));
	return (0);
}
