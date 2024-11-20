#include "../../../headers/header.h"

void		placebo(void *p);
int		algo(t_map s_map, t_queue *q, t_pos_vector i, t_hashtable *visited);
void		__destroy_element_map(void *e);
t_ff		*__create_element(float x, float y);

int	__flood_fill(t_map *s_map)
{
	t_queue		*q;
	t_hashtable	*visited;
	t_pos_vector	i;
	int		ret;

	i.x = s_map->start.x;
	i.y = s_map->start.y;
	i.w = s_map->exit.x;
	i.h = s_map->exit.y;
	q = new_queue();
	q->add(__create_element(i.x, i.y), q);
	visited = new_hashtable(HTABLE_SIZE);
	ret = algo(*s_map, q, i, visited);
	visited->destroy(visited, __destroy_element_map);
	q->destroy(q, __destroy_element_map);
	if (ret)
		s_map->error[7] = 1;
	return (ret);
}
