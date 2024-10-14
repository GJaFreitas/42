#include "../../../headers/header.h"


int	get_distance(t_pos_vector node1, t_pos_vector node2)
{
	int	ret;
	int	x_dist;
	int	y_dist;

	x_dist = i_abs(node1.x - node2.x);
	y_dist = i_abs(node1.y - node2.y);
	if (x_dist < y_dist)
	{
		ret = x_dist * 14;
		y_dist -= x_dist;
		ret += y_dist * 10;
	}
	else
	{
		ret = y_dist * 14;
		x_dist -= y_dist;
		ret += x_dist * 10;
	}
	return (ret);
}

t_gridnode	*__cost(t_gridnode *node, t_astar astar)
{
	node->gcost = get_distance(node->pos, astar.startNode->pos);
	node->hcost = get_distance(node->pos, astar.targetNode->pos);
	node->fcost = node->gcost + node->hcost;
	return (node);
}
