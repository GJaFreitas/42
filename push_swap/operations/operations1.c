#include "../includes/push_swap.h"

void	sa(t_ps *data)
{
	t_stack	*s;
	int	temp;
	int	temp2;

	s = data->a;
	if (s->size < 2)
		return ;
	temp = stack_pop(s);
	temp2 = stack_pop(s);
	stack_add(s, temp);
	stack_add(s, temp2);
	save_move(data, o_sa);
}

void	sb(t_ps *data)
{
	t_stack	*s;
	int	temp;
	int	temp2;

	s = data->b;
	if (s->size < 2)
		return ;
	temp = stack_pop(s);
	temp2 = stack_pop(s);
	stack_add(s, temp);
	stack_add(s, temp2);
	save_move(data, o_sb);
}

void	ss(t_ps *data)
{
	if (data->b->size < 2 || data->a->size < 2)
		return ;
	sa(data);
	sb(data);
	save_move(data, o_ss);
}

void	pa(t_ps *data)
{
	if (data->b->size > 0)
		stack_add(data->a, stack_pop(data->b));
	save_move(data, o_pa);
}

void	pb(t_ps *data)
{
	if (data->a->size > 0)
		stack_add(data->b, stack_pop(data->a));
	save_move(data, o_pb);
}
