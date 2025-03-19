#include "../includes/push_swap.h"

const char	*op_to_string(t_op op)
{
	static const char	*strings[12];
	strings[0] = "none";
	strings[1] = "pa";
	strings[2] = "pb";
	strings[3] = "ra";
	strings[4] = "rb";
	strings[5] = "rr";
	strings[6] = "rra";
	strings[7] = "rrb";
	strings[8] = "rrr";
	strings[9] = "sa";
	strings[10] = "sb";
	strings[11] = "ss";
	return (strings[op]);
}

t_op	string_to_op(char *str)
{
	if (!ft_strncmp("pa", str, 3))
		return (o_pa);
	if (!ft_strncmp("pb", str, 3))
		return (o_pb);
	if (!ft_strncmp("ra", str, 3))
		return (o_ra);
	if (!ft_strncmp("rb", str, 3))
		return (o_rb);
	if (!ft_strncmp("rr", str, 3))
		return (o_rr);
	if (!ft_strncmp("rra", str, 3))
		return (o_rra);
	if (!ft_strncmp("rrb", str, 3))
		return (o_rrb);
	if (!ft_strncmp("rrr", str, 3))
		return (o_rrr);
	if (!ft_strncmp("sa", str, 3))
		return (o_sa);
	if (!ft_strncmp("sb", str, 3))
		return (o_sb);
	if (!ft_strncmp("ss", str, 3))
		return (o_ss);
	return (0);
}

void	save_move(char *op, t_ps *data)
{
	ft_addback_dlist(&data->op_list, ft_new_dlist(string_to_op(op)));
}

void	print_ops(t_ps *data)
{
	t_dlist	*list;

	list = data->op_list;
	while (list)
	{
		ft_printf("%s\n", op_to_string(list->op));
		list = list->next;
	}
}
