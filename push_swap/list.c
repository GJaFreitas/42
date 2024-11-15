#include "push_swap.h"

t_dlist	*newNode(int n)
{
	t_dlist	*new;

	new = ft_calloc(1, sizeof(t_dlist));
	new->n = n;
	return (new);
}

void	addBack(t_dlist *node, t_dlist **head, t_dlist **tail)
{
	t_dlist	*current;

	current = *head;
	if (!node || !head || !tail)
		return ;
	while (current && current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
}
