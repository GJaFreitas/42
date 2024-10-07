#include "../../../headers/header.h"

t_node	*__nodeFromPos(t_pos_vector pos);

// Return true if no colision
byte	__check_wal(int x, int y, float size)
{
	return (!(game()->walls[x][y] ||\
	game()->walls[(int)(x + size)][y] ||\
	game()->walls[x][(int)(y + size)] ||\
	game()->walls[(int)(x + size)][(int)(y + size)]));
}

t_node	*newNode(byte _walkable, t_pos_vector _pos)
{
	t_node	*ret_node;

	ret_node = malloc_safe(sizeof(t_node));
	ret_node->walkable = _walkable;
	ft_memcpy(&ret_node->pos, &_pos, sizeof(t_pos_vector));
	return (ret_node);
}

// Return a 2D array of node pointers
t_node	***__create_grid(t_grid s_grid)
{
	t_node	***grid;
	int	y;
	int	x;

	y = 0;
	grid = malloc_safe(sizeof(t_node **) * (s_grid.gridSizeY + 1));
	while (y < s_grid.gridSizeY)
	{
		grid[y] = malloc_safe(sizeof(t_node *) * (s_grid.gridSizeX + 1));
		x = 0;
		while (x < s_grid.gridSizeX)
		{
			grid[y][x] = newNode(__check_wal(x, y, s_grid.nodeRadius*2), (t_pos_vector){x, y, 0,0});
			x++;
		}
		y++;
	}
	return (grid);
}

void	newGrid()
{
	grid()->nodeRadius = (canva()->scale_factor_e / 2);
	grid()->gridSizeX = (int)(WIDTH / (grid()->nodeRadius * 2));
	grid()->gridSizeY = (int)(HEIGHT / (grid()->nodeRadius * 2));
	grid()->grid = __create_grid(*(grid()));
}

t_grid	*grid()
{
	static t_grid	grid = {0,{0,0,0,0},0,0,0,__nodeFromPos};

	return (&grid);
}
