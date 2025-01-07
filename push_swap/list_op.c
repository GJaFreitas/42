#include "dlinked_list/dlinked_list.h"
#include "libft/libft.h"
#include "push_swap.h"

t_dlist	*exec_instruction(char *str, int flag)
{
	static t_dlist	list;

	if (flag)
		addFront(newNode(str), &list);
	else
		return (&list);
	return (NULL);
}

static int	combination_checker(t_dlnode *current, char *i1, char *i2)
{
		if (!ft_strncmp(current->content, i1, 3)\
      		&& !ft_strncmp(current->next->content, i2, 3)\
      		||!ft_strncmp(current->content, i2, 3)\
      		&& !ft_strncmp(current->next->content, i1, 3))
		return (1);
	return (0);
}

static void	optimize(t_dlist *list, t_dlnode *current, char *str)
{
	destroyNode(pop_this(list, current->next));
	free(current->content);
	current->content = ft_strdup(str);
}

static void	redundancy(t_dlist *list, t_dlnode *current)
{
	destroyNode(pop_this(list, current->next));
	destroyNode(pop_this(list, current));
}

/*
 *
 * sa + sb = ss; ra + rb = rr; rra + rrb = rrr
 *
 * pa + pb; sa + sa; ra + rra
 *
 */
t_dlist	*optimize_instructions(t_dlist *list)
{
	t_dlnode	*current;

	current = list->head;
	while (current->next != NULL)
	{
		if (combination_checker(current, "sa", "sb"))
			optimize(list, current, "ss");
		if (combination_checker(current, "ra", "rb"))
			optimize(list, current, "rr");
		if (combination_checker(current, "rra", "rrb"))
			optimize(list, current, "rrr");
		if (combination_checker(current, "pa", "pb"))
			redundancy(list, current);
		if (combination_checker(current, "sa", "sa"))
			redundancy(list, current);
		if (combination_checker(current, "sb", "sb"))
			redundancy(list, current);
		if (combination_checker(current, "ra", "rra"))
			redundancy(list, current);
		if (combination_checker(current, "rb", "rrb"))
			redundancy(list, current);
		current = current->next;
	}
	return (list);
}
