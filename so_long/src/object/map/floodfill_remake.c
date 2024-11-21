#include "../../../headers/header.h"

void	__flood_fill_r(t_map *s_map, int x, int y)
{
	if (s_map->exit.x == x && s_map->exit.y == y)
		s_map->error[7] = 0;
	if (s_map->map_ptr[x][y] == 'C')
		s_map->hp++;
	if (s_map->hp == s_map->collectible_num)
		s_map->error[8] = 0;
	s_map->map_ptr[x][y] = '1';
	if (y < s_map->row && s_map->map_ptr[x][y + 1] != '1')
		return (__flood_fill_r(s_map, x, y++));
	if (x < s_map->col && s_map->map_ptr[x + 1][y] != '1')
		return (__flood_fill_r(s_map, x++, y));
}
