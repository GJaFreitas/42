#include "../push_swap.h"

// Reverse rotate stack "s"
void	rra(t_stack *s)
{
	stack_rev_rotate(s);
	ft_printf("rra\n");
}

void	rrb(t_stack *s)
{
	stack_rev_rotate(s);
	ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	ft_printf("rrr\n");
}
