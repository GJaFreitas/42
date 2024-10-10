#include "../../../headers/header.h"

static int	gcost(t_gridnode src, t_gridnode dst)
{
}

static int	hcost(t_gridnode src, t_gridnode dst)
{
}

static int	fcost(t_gridnode src, t_gridnode dst)
{
}

// TODO: Ugh
void	astar(t_pos_vector start, t_pos_vector target)
{
	t_heap		*openSet;
	t_hashtable	*closedSet;
	t_gridnode	*startNode;
	t_gridnode	*targetNode;
	t_gridnode	*current;
	t_list		*neighbours;

	startNode = grid()->nodeFromPos(start);
	targetNode = grid()->nodeFromPos(target);
	openSet->add(startNode, openSet);
	while (openSet->itemCount > 0)
	{
		current = openSet->pop(openSet);
		closedSet->insert(grid()->key(current), current, closedSet);
		if (current == targetNode)
			return ;
		neighbours = grid()->get_neighbours(current);
		while (neighbours)
		{
			neighbours = neighbours->next;
		}
	}
}
