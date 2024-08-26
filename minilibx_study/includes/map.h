#ifndef MAP_H
# define MAP_H

typedef struct s_map
{
	unsigned char	*map;
	int		col;
	int		row;
	int		fd;
} s_map;
typedef s_map *t_map;

#endif
