#include "../push_swap.h"

void	ra(t_stack *s)
{
	stack_rotate(s);
}

void	rb(t_stack *s)
{
	stack_rotate(s);
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
}
