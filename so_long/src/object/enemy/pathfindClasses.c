#include "../../../headers/header.h"

t_gridnode	*__nodeFromPos(t_pos_vector pos);
t_hashtable	*__populate_table();
char		*__get_key(t_gridnode *node);
void		__get_neighbours(t_gridnode *node, void **neighbours);

// Return true if no colision
byte	__check_wal(int x, int y, float size)
{
	return (!(game()->walls[x][y] ||\
	game()->walls[(int)(x + size)][y] ||\
	game()->walls[x][(int)(y + size)] ||\
	game()->walls[(int)(x + size)][(int)(y + size)]));
}

t_gridnode	*newNode(byte _walkable, t_pos_vector _pos, int gridX, int gridY)
{
	t_gridnode	*ret_gridnode;

	ret_gridnode = malloc_safe(sizeof(t_gridnode));
	ret_gridnode->walkable = _walkable;
	ret_gridnode->gridX = gridX;
	ret_gridnode->gridY = gridY;
	ret_gridnode->key = grid()->key(ret_gridnode);
	ft_memcpy(&ret_gridnode->pos, &_pos, sizeof(t_pos_vector));
	return (ret_gridnode);
}

// Return a 2D array of node pointers
t_gridnode	***__create_grid(t_grid s_grid)
{
	t_gridnode	***grid;
	int	y;
	int	x;

	y = 0;
	grid = malloc_safe(sizeof(t_gridnode **) * (s_grid.gridSizeY + 1));
	while (y < s_grid.gridSizeX)
	{
		grid[y] = malloc_safe(sizeof(t_gridnode *) * (s_grid.gridSizeX + 1));
		x = 0;
		while (x < s_grid.gridSizeY)
		{
			grid[y][x] = newNode(__check_wal(x, y, s_grid.nodeRadius*4),\
			(t_pos_vector){x, y, 0,0}, x, y);
			x++;
		}
		y++;
	}
	return (grid);
}

// This ↑ function may be a little confusing because of the switched X and Y but that is just bc
// I was too lazy to actually switch the variables and instead just switched the gridSize one

void	newGrid()
{
	grid()->nodeRadius = (canva()->scale_factor_e / 4);
	grid()->gridSizeX = (int)(WIDTH / (grid()->nodeRadius * 2));
	grid()->gridSizeY = (int)(HEIGHT / (grid()->nodeRadius * 2));
	grid()->grid = __create_grid(*(grid()));
}

t_grid	*grid()
{
	static t_grid	grid = {0,{0,0,0,0},0,0,0,\
		__nodeFromPos,__get_neighbours,__get_key};

	return (&grid);
}
