#ifndef GRID_H
#define GRID_H

#include "hashtable.h"
#include "helper_structs.h"
#include "../libs/libft/libft.h"

typedef unsigned char byte;

typedef struct s_grid t_grid;
typedef struct s_gridnode t_gridnode;

struct s_gridnode
{
	byte		walkable;
	int		gcost;
	int		hcost;
	int		fcost;
	int		gridX;
	int		gridY;
	t_pos_vector	pos;
};

struct s_grid
{
	t_gridnode		***grid;
	t_pos_vector	mapSize;
	float		nodeRadius;
	int		gridSizeX;
	int		gridSizeY;

	t_gridnode		*(*nodeFromPos)(t_pos_vector pos);
	t_list		*(*get_neighbours)(t_gridnode *node);
	char		*(*key)(t_gridnode *node);
};

t_grid	*grid();
void	newGrid();
t_gridnode	*newNode(byte _walkable, t_pos_vector _pos, int gridX, int gridY);

#endif
