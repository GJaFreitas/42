#include "includes/push_swap.h"
#include "stack/stack.h"

int	test(t_ps *data)
{
	t_chunk	b;

	b.pos = TOP_B;
	b.size = 3;
	pb(data);
	pb(data);
	pb(data);
	printf("Start:\n");
	stack_print(data->a);
	sort_three(data, &b);
	printf("\n");
	printf("End:\n");
	stack_print(data->a);
	printf("-------------\n");
	return (0);
}
