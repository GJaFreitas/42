#include "../../headers/header.h"

int	__compare(t_item item1, t_item item2, int (*compare)(void *, void *))
{
	return (compare(item1.value, item2.value));
}

void	__for_each(void (*fun)(t_item *), t_heap *heap)
{
	int	index;

	index = 0;
	if (!fun || !heap)
		return ;
	while (index < heap->itemCount)
		fun(&heap->items[index++]);
}

void	*__heap_pop_first(t_heap *heap)
{
	return (heap->remove(heap->items[0], heap);
}
