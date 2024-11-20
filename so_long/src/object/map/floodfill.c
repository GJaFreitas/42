#include "../../../headers/header.h"

void		placebo(void *p);

// x = key % 1024
// y = key / 1024
// https://stackoverflow.com/questions/12764645/good-hash-function-with-2-integer-for-a-special-key
static char	*key(float x, float y)
{
	char	*key;

	key = ft_itoa(x + y * 1024);
	return (key);
}

static void	__destroy_element(void *e)
{
	free(((t_ff*)e)->key);
	free(e);
}

static t_ff	*__create_element(float x, float y)
{
	t_ff	*p;

	p = malloc_safe(sizeof(t_pos_vector));
	p->pos.x = x;
	p->pos.y = y;
	p->key = key(x, y);
	return(p);
}

// Tbh this could be a lot better performance wise if only i could use more lines or
// have more functions in a single file but the norm says that bad code rules
// i should be using a static char current_key[128] and just writing the key in there and
// then wiping it buuut i dont feel like creating 3 files just for the flood fill algo

static void	get_neighbours(t_map s_map, t_queue *q, t_pos_vector current, t_hashtable *visited)
{
	t_ff	*new;
	char	*current_key;
	int	x;
	int	y;

	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
			current_key = key(current.x + x, current.y + y);
			if (x && y && !visited->contains(current_key, visited)
			&& current.x + x >= 0 && current.x + x < s_map.col
			&& current.y + y >= 0 && current.y + y < s_map.row)
			{
				new = __create_element(current.x + x, current.y + y);
				q->add(new, q);
				visited->insert(new->key, new, visited);
			}
			free(current_key);
			y++;
		}
		x++;
	}
}


/*
BFS:
create a queue Q 
mark v as visited and put v into Q 
while Q is non-empty 
    remove the head u of Q 
    mark and enqueue all (unvisited) neighbours of u

*/

// Return 0 if there is a path from the start to the exit and 1 otherwise
static int	algo(t_map s_map, t_queue *q, t_pos_vector i, t_hashtable *visited)
{
	t_ff	*current;

	while (q->top)
	{
		current = q->pop(q);
		visited->insert(current->key, current, visited);
		get_neighbours(s_map, q, current->pos, visited);
		if (current->pos.x == i.w && current->pos.y == i.h)
			return (free(current), 0);
		free(current); 
	}
	return (1);
}

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
	visited->destroy(visited, placebo);
	q->destroy(q, __destroy_element);
	if (ret)
		s_map->error[7] = 1;
	return (ret);
}
