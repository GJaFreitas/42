#include "../../../headers/header.h"

/*

create a queue Q 
mark v as visited and put v into Q 
while Q is non-empty 
    remove the head u of Q 
    mark and enqueue all (unvisited) neighbours of u

*/

static t_pos_vector	*__create_element(float x, float y)
{
	t_pos_vector	*p;

	p = malloc_safe(sizeof(t_pos_vector));
	p->x = x;
	p->y = y;
	return(p);
}

static int	algo(t_map s_map, t_queue *q, t_pos_vector i)
{
}

int	__flood_fill(t_map s_map)
{
	t_queue		*q;
	t_pos_vector	i;
	int		ret;

	q = new_queue();
	q->add(__create_element(i.x, i.y), q);
	i.x = s_map.start.x;
	i.y = s_map.start.y;
	i.w = s_map.exit.x;
	i.h = s_map.exit.y;
	ret = algo(s_map, q, i);
	q->destroy(q, 1);
	return (ret);
}
