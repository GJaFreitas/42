#include "../includes/push_swap.h"

// TODO: Check for duplicate numbers in stack

static const char	*op_to_string(t_op op)
{
	static const char	*strings[12];

	strings[0] = "null_op";
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

void	save_move(t_ps *data, t_op op)
{
	char	*content;

	content = ft_strdup(op_to_string(op));
	/*
	printf("Operation: %s\n", content);
	printf("Stack A:\n");
	stack_print(data->a);
	printf("\nStack B:\n");
	stack_print(data->b);
	printf("\n\n");
	*/
	ft_lstadd_back(&data->op_list, ft_lstnew(content));
}

void	print_op(t_list *current)
{
	while (current)
	{
		ft_printf("%s\n", (char *)current->content);
		current = current->next;
	}
}
