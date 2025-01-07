#include "push_swap.h"

void	exec_instruction(t_stack *a, t_stack *b, char *str)
{
	if (!ft_strncmp(str, "sa", 3))
		sa(a);
	else if (!ft_strncmp(str, "sb", 3))
		sb(b);
	else if (!ft_strncmp(str, "ss", 3))
		ss(a, b);
	else if (!ft_strncmp(str, "ra", 3))
		ra(a);
	else if (!ft_strncmp(str, "rb", 3))
		rb(b);
}

void	exec(t_stack *a, t_stack *b, t_dlist *list)
{
	t_dlnode	*current;

	current = list->head;
	while (current != NULL)
	{
		exec_instruction(a, b, current->content);
		current = current->next;
	}
}
