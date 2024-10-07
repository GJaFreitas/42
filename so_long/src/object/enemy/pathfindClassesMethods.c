#include "../../../headers/header.h"

t_node	*__nodeFromPos(t_pos_vector pos)
{
	int	x;
	int	y;
	float	percentX;
	float	percentY;

	percentX = pos.x / WIDTH;
	percentY = pos.y / HEIGHT;
	x = (int)((grid()->gridSizeX - 1) * percentX);
	y = (int)((grid()->gridSizeY - 1) * percentY);
	return (grid()->grid[x][y]);
}
