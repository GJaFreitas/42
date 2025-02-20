#include "../push_swap.h"

void	ra(t_stack *s)
{
	stack_rotate(s);
	ft_printf("ra\n");
}

void	rb(t_stack *s)
{
	stack_rotate(s);
	ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b)
{
	ra(a);
	rb(b);
	ft_printf("rr\n");
}
