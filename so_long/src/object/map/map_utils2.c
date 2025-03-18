#include "../../../headers/header.h"

void	__map_handler(char c, t_map *s_map, t_pos_vector pos);
byte	__check_walls(t_map *s_map);

// Checks if there is an exit, a start and at least 1 collectible
void	__check_components(t_map *s_map)
{
	if (s_map->start.x == 0)
		s_map->error[2] = 1;
	if (s_map->exit.x == 0)
		s_map->error[3] = 1;
	if (!count_obj(COLLECTIBLE))
		s_map->error[6] = 1;
}

// returns the error flags value
byte	__map_check(t_map *s_map)
{
	char	**map;
	int		i;
	int		j;

	i = 0;
	map = s_map->map_ptr;
	if (__check_walls(s_map))
		return (s_map->error[1] = 1, 1);
	while (i < s_map->row)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != '0')
				__map_handler(map[i][j], s_map,\
					(t_pos_vector) {i, j, 0, 0});
			j++;
		}
		i++;
	}
	__check_components(s_map);
	i = 0;
	while (i < 7)
		if (s_map->error[i++])
			return (1);
	return (0);
}
