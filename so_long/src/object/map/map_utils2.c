#include "../../../headers/header.h"

void	__map_handler(char c, t_map *s_map, t_pos_vector pos);
byte	__check_walls(t_map *s_map);

// returns the error flags value
byte	__map_check(t_map *s_map)
{
	char		**map;
	int		i;
	int		j;

	i = 0;
	map = s_map->map_ptr;
	if (__check_walls(s_map))
		return (s_map->error = 1, 1);
	while (i < s_map->row)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0')
				__map_handler(map[i][j], s_map,\
					(t_pos_vector){i, j, 0, 0});
			j++;
		}
		i++;
	}
	return (s_map->error);
}
