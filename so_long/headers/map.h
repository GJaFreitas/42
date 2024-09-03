#ifndef MAP_H
# define MAP_H

typedef unsigned char byte;
typedef struct s_map t_map;

struct s_map
{
	char	**map_ptr;
	int		row;
	int		col;
	byte		start;
	byte		exit;
};

#endif
