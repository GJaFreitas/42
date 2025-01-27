#include "../push_swap.h"

void	ra(t_stack *s)
{
	stack_rotate(s);
	m_count("ra");
}

void	rb(t_stack *s)
{
	stack_rotate(s);
	m_count("rb");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	m_count("rr");
}
