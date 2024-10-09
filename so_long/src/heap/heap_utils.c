#include "../../headers/header.h"

void	__swap(t_item *item1, t_item *item2)
{
	void	*temp;

	temp = item1->value;
	item1->value = item2->value;
	item2->value = temp;
}

void	__sort_down(t_item item, t_heap *heap)
{
	t_item	parentItem;
	int	parentIndex;

	if (!heap)
		return ;
	parentIndex = (item.index - 1) / 2;
	parentItem = heap->items[parentIndex];
	if (heap->compare(item, parentItem, heap->sortFunc) < 0)
	{
		heap->swap(&item, &parentItem);
		heap->sortDown(heap->items[parentIndex], heap);
	}
}

void	__sort_up(t_item item, t_heap *heap)
{
	t_item	parentItem;
	int	parentIndex;

	if (!heap)
		return ;
	parentIndex = (item.index - 1) / 2;
	parentItem = heap->items[parentIndex];
	if (heap->compare(item, parentItem, heap->sortFunc) > 0)
	{
		heap->swap(&item, &parentItem);
		heap->sortUp(heap->items[parentIndex], heap);
	}
}

void	__heap_add(void *value, t_heap *heap)
{
	if (!heap || !value)
		return ;
	heap->items[heap->itemCount].value = value;
	heap->items[heap->itemCount].index = heap->itemCount;
	heap->sortUp(heap->items[heap->itemCount], heap);
	heap->itemCount++;
}

void	__heap_remove(t_item item, t_heap *heap)
{
	int	index;

	if (!heap)
		return ;
	index = item.index;
	free(heap->items[item.index].value);
	heap->swap(&item, &heap->items[heap->itemCount]);
	heap->sortDown(heap->items[index], heap);
}
