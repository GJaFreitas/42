#include "dlinked_list.h"

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
