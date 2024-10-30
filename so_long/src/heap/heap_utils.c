#include "../../headers/header.h"

/*
	*
	* Can't believe how much i was humbled by this, not only because whoever thought
	* of this implementation is a goddamn genius but also because of how hard it was
	* to replicate. And here i thought i was good with pointers.
	*
*/

void	__swap(t_item *item1, t_item *item2)
{
	void	*temp;

	temp = item1->value;
	item1->value = item2->value;
	item2->value = temp;
}

void	__sort_down(t_item item, t_heap *heap)
{
	t_item	leftChild;
	t_item	rightChild;
	int	rightIndex;
	int	leftIndex;

	if (!heap || item.index == (heap->itemCount - 1))
		return ;
	rightIndex = 2 * (item.index + 2);
	rightChild = heap->items[rightIndex];
	leftIndex = 2 * (item.index + 1);
	leftChild = heap->items[leftIndex];
	if (heap->sortFunc(item.value, leftChild.value) < 0)
	{
		heap->swap(&heap->items[item.index], &leftChild);
		heap->sortDown(heap->items[leftIndex], heap);
	}
	else if (heap->sortFunc(item.value, rightChild.value) < 0)
	{
		heap->swap(&heap->items[item.index], &rightChild);
		heap->sortDown(heap->items[rightIndex], heap);
	}
}

void	__sort_up(t_item item, t_heap *heap)
{
	t_item	parentItem;
	int	parentIndex;

	if (!heap || !item.index)
		return ;
	parentIndex = (item.index - 1) / 2;
	parentItem = heap->items[parentIndex];
	if (heap->compare(item, parentItem, heap->sortFunc) > 0)
	{
		heap->swap(&heap->items[item.index], &parentItem);
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

void	*__heap_remove(t_item *item, t_heap *heap)
{
	void	*ret;
	int	index;

	if (!heap)
		return (NULL);
	index = item->index;
	ret = heap->items[index].value;
	heap->swap(item, &heap->items[heap->itemCount - 1]);
	heap->sortDown(heap->items[index], heap);
	heap->itemCount--;
	return (ret);
}
