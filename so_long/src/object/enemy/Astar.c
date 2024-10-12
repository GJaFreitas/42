#include "../../../headers/header.h"

/*
static int	gcost(t_gridnode src, t_gridnode dst)
{
}

static int	hcost(t_gridnode src, t_gridnode dst)
{
}

static int	fcost(t_gridnode src, t_gridnode dst)
{
}
*/

int	__compare_func(void *node1, void *node2)
{
	return (((t_gridnode*)node1)->fcost - ((t_gridnode*)node2)->fcost);
}

static void	__init_astar(t_astar *astar, t_pos_vector start, t_pos_vector target)
{
	ft_bzero(astar, sizeof(t_astar));
	astar->openSet = new_heap(__compare_func);
	astar->closedSet = new_hashtable(HTABLE_SIZE);
	astar->startNode = grid()->nodeFromPos(start);
	astar->targetNode = grid()->nodeFromPos(target);
	astar->openSet->add(astar->startNode, astar->openSet);
}

// TODO: Ugh
void	astar(t_pos_vector start, t_pos_vector target)
{
	t_astar		astar;
	t_gridnode	*current;

	__init_astar(&astar, start, target);
	while (astar.openSet->itemCount > 0)
	{
		current = astar.openSet->pop(astar.openSet);
		astar.closedSet->insert(grid()->key(current), current, astar.closedSet);
		if (current == astar.targetNode)
			return ;
		astar.neighbours = grid()->get_neighbours(current);
		while (astar.neighbours)
		{
			astar.neighbours = astar.neighbours->next;
		}
	}
}
