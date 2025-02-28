#include "../includes/push_swap.h"

static int	__no_mirrors(t_list *list)
{
	t_list	*current;
	t_list	*compare;
	t_op	neutral_op;
	int	n;

	n = 0;
	current = list;
	while (current && current->next)
	{
		neutral_op = oposite_op(*(t_op *)current->content);
		if (neutral_op)
		{
			compare = current->next;
			if (current->prev)
			{
				current = current->prev;
				remove_op(current->next);
				remove_op(compare);
				n++;
			}
		}
		current = current->next;
	}
	return (n);
}

static void	__swap_op(t_list *current, t_op new_op)
{
	free(current->content);
	current->content = ft_strdup(op_to_string(new_op));
}

static int	__merge_opt(t_list *list)
{
	int	n;
	t_list	*current;
	t_op	op;

	n = 0;
	current = list;
	while (current && current->next)
	{
		op = _mergable(string_to_op(current->content),\
		string_to_op(current->next->content));
		if (op)
		{
			n++;
			remove_op(current->next);
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
