#include "../includes/push_swap.h"

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
	ft_printf("sa\n");
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
	ft_printf("sb\n");
}

void	ss(t_stack *a, t_stack *b)
{
	sa(a);
	sb(b);
	ft_printf("ss\n");
}

void	pa(t_stack *a, t_stack *b)
{
	if (b->size > 0)
		stack_add(a, stack_pop(b));
	ft_printf("pa\n");
}

void	pb(t_stack *a, t_stack *b)
{
	if (a->size > 0)
		stack_add(b, stack_pop(a));
	ft_printf("pb\n", b->size);
}
