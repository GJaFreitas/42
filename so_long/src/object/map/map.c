#include "../../../headers/header.h"

void	__map_realloc(char **map, int rows);
void	__load_map(char *filepath, t_map *s_map);
void	__load_coords(t_pos_vector *pos, int x, int y, byte *error);
byte	__map_check(t_map *s_map);

void	__destroy_map(t_map **s_map)
{
	char	**map;
	int		i;

	map = (*s_map)->map_ptr;
	i = 0;
	while (map[i])
		free_safe((void**)&map[i++]);
	free_safe((void**)&(*s_map)->map_ptr);
	free_safe((void**)s_map);
	printf("muahahahaha falhou\n\n\n\n");
}

t_map	*new_map(char *filepath)
{
	t_map	*map;

	map = malloc_safe(sizeof(t_map));
	__load_map(filepath, map);
	map->col = ft_strlen(map->map_ptr[0]);
	if (__map_check(map))
		__destroy_map(&map);
	return (map);
}
