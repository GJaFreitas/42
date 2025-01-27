#include "../push_swap.h"

// Reverse rotate stack "s"
void	rra(t_stack *s)
{
	stack_rev_rotate(s);
	m_count("rra");
}

void	rrb(t_stack *s)
{
	stack_rev_rotate(s);
	m_count("rrb");
}

void	rrr(t_stack *a, t_stack *b)
{
	rra(a);
	rrb(b);
	m_count("rrr");
}
