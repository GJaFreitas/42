#include "../push_swap.h"

void	sa(t_stack *s)
{
	int	temp;
	int	temp2;

	if (s->size < 1)
		return ;
	temp = stack_pop(s);
	temp2 = stack_pop(s);
	stack_add(s, temp);
	stack_add(s, temp2);
	m_count("sa");
}

void	sb(t_stack *s)
{
	int	temp;
	int	temp2;

	if (s->size < 1)
		return ;
	temp = stack_pop(s);
	temp2 = stack_pop(s);
	stack_add(s, temp);
	stack_add(s, temp2);
	m_count("sb");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	m_count("ss");
}

void	pa(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		stack_add(b, stack_pop(a));
	m_count("pa");
}

void	pb(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		stack_add(a, stack_pop(b));
	m_count("pb");
}
