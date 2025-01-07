#include "dlinked_list.h"

t_dlist	*newList()
{
	t_dlist	*list;

	list = ft_calloc(1, sizeof(t_dlist));
	return (list);
}

t_dlnode	*newNode(void *content)
{
	t_dlnode	*new;

	new = ft_calloc(1, sizeof(t_dlnode));
	new->content = content;
	return (new);
}

static void	empty_list(t_dlnode *node, t_dlist *l)
{
	l->head = node;
	l->tail = node;
	l->size = 1;
}

void	addFront(t_dlnode *node, t_dlist *l)
{
	t_dlnode	*prevHead;

	if (!node || !l)
		return ;
	if (!l->head)
		return (empty_list(node, l), (void)0);
	prevHead = l->head;
	l->head = node;
	node->next = prevHead;
	l->size++;
}

void	addBack(t_dlnode *node, t_dlist *l)
{
	t_dlnode	*current;

	current = l->head;
	if (!node || !l)
		return ;
	if (!l->head)
		return (empty_list(node, l), (void)0);
	while (current && current->next)
		current = current->next;
	current->next = node;
	node->prev = current;
	l->tail = node;
	l->size++;
}
