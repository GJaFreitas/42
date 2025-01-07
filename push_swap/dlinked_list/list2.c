#include "dlinked_list.h"

void		addNext(t_dlist *l, t_dlnode *current, void *content)
{
	t_dlnode	*new;
	t_dlnode	*next;

	new = newNode(content);
	next = current->next;
	current->next = new;
	new->next = next;
	new->prev = current;
}

t_dlnode	*pop_head(t_dlist *l)
{
	t_dlnode	*temp;

	temp = l->head;
	l->head = temp->next;
	l->size--;
	return (temp);
}

t_dlnode	*pop_tail(t_dlist *l)
{
	t_dlnode	*temp;

	temp = l->tail;
	l->tail = temp->prev;
	if (temp->prev)
		temp->prev->next = NULL;
	l->size--;
	return (temp);
}

t_dlnode	*pop_this(t_dlist *list, t_dlnode *node)
{
	t_dlnode	*prev;
	t_dlnode	*next;

	if (node == list->head)
		return (pop_head(list));
	if (node == list->tail)
		return (pop_tail(list));
	prev = node->prev;
	next = node->next;
	prev->next = next;
	next->prev = prev;
	return (node);
}

void		destroyNode(t_dlnode *node)
{
	free(node->content);
	free(node);
}
