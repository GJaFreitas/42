#include "../push_swap.h"

// Reverse rotate stack "s"
void	rra(t_stack *s)
{
	stack_rev_rotate(s);
}

void	rrb(t_stack *s)
{
	stack_rev_rotate(s);
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
}
