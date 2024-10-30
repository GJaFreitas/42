#ifndef GRID_H
#define GRID_H

#include "hashtable.h"
#include "heap.h"
#include "helper_structs.h"
#include "../libs/libft/libft.h"

typedef unsigned char byte;

typedef struct s_grid t_grid;
typedef struct s_gridnode t_gridnode;
typedef struct s_astar t_astar;

struct s_astar
{
	t_heap		*openSet;
	t_hashtable	*closedSet;
	t_gridnode	*startNode;
	t_gridnode	*targetNode;
	void		**neighbours;
};

struct s_gridnode
{
	byte		walkable;
	int		gcost;
	int		hcost;
	int		fcost;
	int		gridX;
	int		gridY;
	t_pos_vector	pos;
	t_gridnode	*parent;
	char		*key;
};

struct s_grid
{
	t_gridnode		***grid;
	t_pos_vector	mapSize;
	float		nodeRadius;
	int		gridSizeX;
	int		gridSizeY;

	t_gridnode	*(*nodeFromPos)(t_pos_vector pos);
	void		(*get_neighbours)(t_gridnode *node, void **neighbours);
	char		*(*key)(t_gridnode *node);
};

t_grid	*grid();
void	newGrid();
t_gridnode	*newNode(byte _walkable, t_pos_vector _pos, int gridX, int gridY);

#endif
