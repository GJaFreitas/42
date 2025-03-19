#include "../includes/push_swap.h"

t_dlist	*ft_new_dlist(t_op op)
{
	t_dlist	*new;

	new = ft_calloc(1, sizeof(t_dlist));
	new->op = op;
	return (new);
}

t_dlist	*ft_lstlast_mod(t_dlist *head)
{
	if (head == NULL)
		return (head);
	while (head->next != NULL)
		head = head->next;
	return (head);
}

void	ft_addback_dlist(t_dlist **head, t_dlist *node)
{
	t_dlist	*temp;

	if (!head || !node)
		return ;
	if (!*head)
	{
		*head = node;
		return ;
	}
	temp = ft_lstlast_mod(*head);
	temp->next = node;
	node->prev = temp;
}

void	ft_remove_this(t_dlist *delete)
{
	delete->prev->next = delete->next;
	if (delete->next)
		delete->next->prev = delete->prev;
	free(delete);
}
