#include "../../../headers/header.h"

t_gridnode	*__nodeFromPos(t_pos_vector pos)
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

void	__get_neighbours(t_gridnode *node, void **neighbours)
{
	int	i;
	int	x;
	int	y;

	i = 0;
	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
			if (!x && !y)
				;
			else if (node->gridX + x >= 0 && node->gridX + x < grid()->gridSizeX
			&& node->gridY + y >= 0 && node->gridY + y < grid()->gridSizeY)
				neighbours[i++] = grid()->grid[node->gridX + x][node->gridY + y];
			y++;
		}
		x++;
	}
}
