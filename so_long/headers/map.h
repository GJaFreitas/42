#ifndef MAP_H
# define MAP_H

# include "helper_structs.h"

typedef unsigned char byte;
typedef struct s_map t_map;

struct s_map
{
	char			**map_ptr;
	int			row;
	int			col;
	t_pos_vector		start;
	t_pos_vector		exit;
	t_pos_vector		enemies[128];
	t_pos_vector		collectibles[128];
	byte			error;
};

t_map	*new_map(char *filepath);

#endif
