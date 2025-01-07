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
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
}

void	pa(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		stack_add(b, stack_pop(a));
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		stack_add(b, stack_pop(a));
}
