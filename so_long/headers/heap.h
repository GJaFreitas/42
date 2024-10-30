#ifndef HEAP_H
#define HEAP_H

#define HEAP_SIZE 2048

typedef struct s_heap t_heap;
typedef struct s_item t_item;

struct s_item
{
	void	*value;
	int	index;
};

struct s_heap
{
	t_item	items[HEAP_SIZE];
	int		itemCount;
	void	(*add)(void *value, t_heap *heap);
	void	*(*remove)(t_item *item, t_heap *heap);
	void	*(*pop)(t_heap *heap);
	void	(*sortUp)(t_item item, t_heap *heap);
	void	(*sortDown)(t_item item, t_heap *heap);
	void	(*swap)(t_item *item1, t_item *item2);
	void	(*forEach)(void (*fun)(t_item *, void *), void *v, t_heap *heap);
	int	(*compare)(t_item item1, t_item item2, int (*compare)(void *, void *));
	int	(*sortFunc)(void *, void *);
	int	(*contains)(void *value, t_heap *heap);
	void	(*destroy)(t_heap *heap);
};

t_heap	*new_heap(int (*sortFunc)(void *, void *));

#endif
