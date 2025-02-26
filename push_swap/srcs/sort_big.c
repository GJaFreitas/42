#include "../includes/push_swap.h"

void	chunk_to_the_top(t_ps *data, t_chunk *to_sort)
{
	if (to_sort->pos == BOTTOM_B && data->b->size == to_sort->size)
		to_sort->pos = TOP_B;
	if (to_sort->pos == BOTTOM_A && data->a->size == to_sort->size)
		to_sort->pos = TOP_A;
}

// Recursiveness is magic
static void	recursive_magic(t_ps *data, t_chunk *to_sort)
{
	t_split_dest	dests;

	chunk_to_the_top(data, to_sort);
	if (to_sort->size <= 3)
	{
		if (to_sort->size == 3)
			sort_three(data, to_sort);
		else if (to_sort->size == 2)
			sort_two(data, to_sort);
		else if (to_sort->size == 1)
			sort_one(data, to_sort);
		return ;
	}
	chunk_split(data, to_sort, &dests);
	recursive_magic(data, &dests.min);
	recursive_magic(data, &dests.mid);
	recursive_magic(data, &dests.max);
}

void	chunk_sort(t_ps *data)
{
	t_chunk	big_chunkaroo;

	big_chunkaroo.pos = TOP_A;
	big_chunkaroo.size = data->a->size;
	recursive_magic(data, &big_chunkaroo);
	//optimize_the_stuff(data);
}
