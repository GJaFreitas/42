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

t_list	*__get_neighbours(t_gridnode *node)
{
	t_list	*n;
	int	x;
	int	y;

	x = -1;
	while (x <= 1)
	{
		y = -1;
		while (y <= 1)
		{
			if (!x && !y)
				continue ;
			if (node->gridX + x >= 0 && node->gridX + x < grid()->gridSizeX
			&& node->gridY + y >= 0 && node->gridY + y < grid()->gridSizeY)
				ft_lstadd_front(&n, ft_lstnew(grid()->grid[node->gridX + x][node->gridY + y]));
			y++;
		}
		x++;
	}
	return (n);
}
