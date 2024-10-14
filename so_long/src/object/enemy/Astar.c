#include "../../../headers/header.h"

t_gridnode	*__cost(t_gridnode *node, t_astar astar);
int		get_distance(t_pos_vector node1, t_pos_vector node2);
void		placebo(void *p);

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

// recursive list transversaltransversal
static void	foreach(t_gridnode *current, t_list *list, t_astar *astar) 
{
	t_gridnode	*neighbour;
	int		newCostToNeighbour;

	while (list && (!((t_gridnode*)(list->content))->walkable\
	|| astar->closedSet->contains(list->content, astar->closedSet)))
		list = list->next;
	if (!list)
		return ;
	neighbour = list->content;
	newCostToNeighbour = current->gcost + get_distance(current->pos, neighbour->pos);
	if (newCostToNeighbour < neighbour->gcost\
	|| astar->openSet->contains(neighbour, astar->openSet))
	{
		neighbour = __cost(neighbour, *astar);
		neighbour->parent = current;
		if (!astar->openSet->contains(neighbour, astar->openSet))
			astar->openSet->add(neighbour, astar->openSet);
	}
	foreach(current, list, astar);
}

t_list	*retrace_path(t_gridnode *start, t_gridnode *target)
{
	t_list		*path;
	t_gridnode	*current;

	current = target;
	while (current && current != start)
	{
		ft_lstadd_front(&path, ft_lstnew(current));
		current = current->parent;
	}
	return (path);
}

t_list	*astar(t_pos_vector start, t_pos_vector target)
{
	t_astar		astar;
	t_gridnode	*current;

	__init_astar(&astar, start, target);
	while (astar.openSet->itemCount > 0)
	{
		current = __cost(astar.openSet->pop(astar.openSet), astar);
		astar.closedSet->insert(grid()->key(current), current, astar.closedSet);
		if (current == astar.targetNode)
			return (retrace_path(astar.startNode, astar.targetNode));
		astar.neighbours = grid()->get_neighbours(current);
		foreach(current, astar.neighbours, &astar);
	}
	ft_lstclear(&astar.neighbours, placebo);
	astar.openSet->destroy(astar.openSet);
	astar.closedSet->destroy(astar.closedSet, placebo);
	return (retrace_path(astar.startNode, astar.targetNode));
}
