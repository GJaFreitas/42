#ifndef GRID_H
#define GRID_H

#include "helper_structs.h"

typedef unsigned char byte;

typedef struct s_grid t_grid;
typedef struct s_node t_node;

struct s_node
{
	byte		walkable;
	t_pos_vector	pos;
};

struct s_grid
{
	t_node		***grid;
	t_pos_vector	mapSize;
	float		nodeRadius;
	int		gridSizeX;
	int		gridSizeY;

	t_node		*(*nodeFromPos)(t_pos_vector pos);
};

t_grid	*grid();
void	newGrid();
t_node	*newNode(byte _walkable, t_pos_vector _pos);

#endif
