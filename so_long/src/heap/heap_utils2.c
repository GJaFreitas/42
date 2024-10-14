#include "../../headers/header.h"

int	__compare(t_item item1, t_item item2, int (*compare)(void *, void *))
{
	return (compare(item1.value, item2.value));
}

void	__for_each(void (*fun)(t_item *, void *), void *v, t_heap *heap)
{
	int	index;

	index = 0;
	if (!fun || !heap)
		return ;
	while (index < heap->itemCount)
		fun(&heap->items[index++], v);
}

void	*__heap_pop_first(t_heap *heap)
{
	return (heap->remove(heap->items[0], heap));
}

int	__contains_heap(void *value, t_heap *heap)
{
	int	index;

	index = 0;
	if (!value || !heap)
		return (0);
	while (index < heap->itemCount)
		if (heap->items[index++].value == value)
			return (1);
	return (0);
}

void	__destroy_heap(t_heap *heap)
{
	free(heap);
}
