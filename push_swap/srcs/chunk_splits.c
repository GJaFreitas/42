#include "../includes/push_swap.h"

void	set_split_dest(t_pos pos, t_chunk *min, t_chunk *mid, t_chunk *max)
{
	if (pos == TOP_A)
	{
		max->pos = BOTTOM_B;
		mid->pos = TOP_B;
		min->pos = BOTTOM_A;
	}
	else if (pos == BOTTOM_A)
	{
		max->pos = BOTTOM_B;
		mid->pos = TOP_B;
		min->pos = TOP_A;
	}
	else if (pos == TOP_B)
	{
		max->pos = BOTTOM_B;
		mid->pos = BOTTOM_A;
		min->pos = TOP_A;
	}
	else if (pos == BOTTOM_B)
	{
		max->pos = TOP_B;
		mid->pos = BOTTOM_A;
		min->pos = TOP_A;
	}
}

void	set_pivots(t_pos pos, int size, int *piv1, int *piv2)
{
	*piv2 = size / 3;
	if (pos == TOP_A || pos == BOTTOM_A)
		*piv1 = 2 * size / 3;
	if (pos == TOP_B || pos == BOTTOM_B)
		*piv1 = size / 2;
	if (pos == BOTTOM_B && size < 8)
		*piv2 = size / 2;
	if ((pos == TOP_A || pos == BOTTOM_A) && size < 15)
		*piv1 = size;
}

/*
 
	Logic behind the logic:

	if (next > max - pivot[0]):
		max - pivot[0] is the top part of the chunk, since i have normalized the values in
		the stack if the chunk has size 10 then the values in there pretty much
		are equal to the ints from 1 to 10, [1 - 10] then max - pivot[0] will be
		2/3 of the way up or halfway up so == 5 || 7
	
	if (next > max - pivot[1]
		following the same logic here if the value wasnt in max - pivot[0] but is
		int max - pivot[1] then that means its a median value, in the middle of the nums
		like 3 or 4 in the previous case, so next would be more than (3 || 4) and less
		than (5 || 7)
	
	the final case is if it is a small value

	         pivot1     pivot2
	[    min   |   mid    |    max   ]

*/

// Splits chunks
void	chunk_split(t_ps *data, t_chunk *to_split, t_split_dest *dest)
{
	int	pivot1;
	int	pivot2;
	int	max;
	int	next;

	ft_bzero(dest, sizeof(t_split_dest));
	set_split_dest(to_split->pos, &dest->min, &dest->mid, &dest->max);
	set_pivots(to_split->pos, to_split->size, &pivot1, &pivot2);
	max = chunk_max(data, to_split);
	while (to_split->size--)
	{
		next = chunk_get(data, to_split, 1);
		if (next > max - pivot2)
			dest->max.size += move_from_to(data, to_split->pos, dest->max.pos);
		else if (next > max - pivot1)
			dest->mid.size += move_from_to(data, to_split->pos, dest->mid.pos);
		else
			dest->min.size += move_from_to(data, to_split->pos, dest->min.pos);
	}
}
