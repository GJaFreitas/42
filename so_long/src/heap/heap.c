#include "../../headers/header.h"

void	__sort_down(t_item item, t_heap *heap);
void	__sort_up(t_item item, t_heap *heap);
void	__heap_add(void *value, t_heap *heap);
void	__heap_remove(t_item item, t_heap *heap);
void	__swap(t_item *item1, t_item *item2);
int	__compare(t_item item1, t_item item2, int (*compare)(void *, void *));
void	__for_each(void (*fun)(t_item *), t_heap *heap);

t_heap	*new_heap(int (*sortFunc)(void *, void *))
{
	t_heap	*heap;

	heap = malloc_safe(sizeof(t_heap));
	heap->sortFunc = sortFunc;
	heap->add = __heap_add;
	heap->remove = __heap_remove;
	heap->sortUp = __sort_up;
	heap->sortDown = __sort_down;
	heap->swap = __swap;
	heap->compare = __compare;
	heap->forEach = __for_each;
	return (heap);
}