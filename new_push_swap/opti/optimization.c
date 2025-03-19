#include "../includes/push_swap.h"

static int	__no_mirrors(t_dlist *list)
{
	t_dlist	*current;
	t_dlist	*compare;
	t_op	neutral_op;
	int		n;
	n = 0;
	current = list;
	while (current && current->next)
	{
		neutral_op = oposite_op(current->op);
		if (neutral_op)
		{
			compare = current->next;
			if (current->prev)
			{
				current = current->prev;
				ft_remove_this(current->next);
				ft_remove_this(compare);
				n++;
			}
		}
		current = current->next;
	}
	return (n);
}

static void	__swap_op(t_dlist *current, t_op new_op)
{
	current->op = new_op;
}

static int	__merge_opt(t_dlist *list)
{
	t_dlist	*current;
	t_op	op;
	int		n;
	n = 0;
	current = list;
	while (current && current->next)
	{
		op = _mergable(current->op, current->next->op);
		if (op)
		{
			n++;
			ft_remove_this(current->next);
			__swap_op(current, op);
		}
		current = current->next;
	}
	return (n);
}

void	post_sort_opt(t_ps *data)
{
	int	merge;
	int	mirror;
	if (!data->op_list)
		return ;
	mirror = __no_mirrors(data->op_list);
	merge = __merge_opt(data->op_list);
	(void)merge;
	(void)mirror;
}
